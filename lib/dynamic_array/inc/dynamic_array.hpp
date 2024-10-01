/*
 *  The MIT License (MIT)
 * Copyright (c) 2024 Enix Yu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
class DynamicArray {
 public:
  explicit DynamicArray(size_t capacity);
  explicit DynamicArray(T data[], size_t size, size_t capacity);
  ~DynamicArray();

  size_t Size() { return size_; }
  size_t Capacity() { return capacity_; }
  void Append(T &&elem);
  void Add(size_t index, T &&elem);
  void Delete(size_t index);
  bool IsEmpty() const;
  T &Get(size_t index);

 private:
  T *data_;
  size_t size_;
  size_t capacity_;
};

template <typename T>
DynamicArray<T>::DynamicArray(size_t capacity) {
  data_ = new T[capacity];
  capacity_ = capacity;
  size_ = 0;
}

template <typename T>
DynamicArray<T>::DynamicArray(T data[], size_t size, size_t capacity) {
  if (capacity < size) {
    throw std::invalid_argument("capacity should be greater than or equal size");
  }
  data_ = new T[capacity];
  std::copy(data, data + size, data_);
  capacity_ = capacity;
  size_ = size;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  delete[] data_;
}

template <typename T>
void DynamicArray<T>::Append(T &&elem) {
  Add(size_, elem);
}

template <typename T>
void DynamicArray<T>::Add(size_t index, T &&elem) {
  if (index > size_) {
    throw std::out_of_range("invalid index");
  }
  if (size_ == capacity_) {
    capacity_ *= 2;
    T *newData = new T[capacity_];
    if (index > 0) {
      std::copy(data_, data_ + index, newData);
    }
    if (index < size_) {
      std::copy(data_ + index, data_ + size_ + 1, newData + index + 1);
    }
    delete data_;
    data_ = newData;
  } else if (index < size_) {
    std::copy(data_ + index, data_ + size_ + 1, data_ + index + 1);
  }
  data_[index] = elem;
  size_++;
}

template <typename T>
void DynamicArray<T>::Delete(size_t index) {
  if (index > size_) {
    throw std::out_of_range("invalid index");
  }
  if (index != size_) {
    std::copy(data_ + index + 1, data_ + size_, data_ + index);
  }
  size_--;
}

template <typename T>
bool DynamicArray<T>::IsEmpty() const {
  return size_ == 0;
}

template <typename T>
T &DynamicArray<T>::Get(size_t index) {
  if (index < 0 || index >= size_) {
    throw std::out_of_range("index out of bound");
  }
  return data_[index];
}
