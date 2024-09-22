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

#include <algorithm>>

template <typename T>
class DynamicArray {
 public:
  explicit DynamicArray(int capacity);
  ~DynamicArray();

  void Append(T &elem);
  void Add(int index, T &elem);
  void Delete(int index);
  bool IsEmpty() const;

 private:
  T *data_;
  int size_;
  int capacity_;
  void EnsureCapacity();
};

template <typename T>
DynamicArray<T>::DynamicArray(int capacity) {
  data_ = new T[capacity];
  capacity_ = capacity;
  size_ = 0;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  delete data_;
}

template <typename T>
void DynamicArray<T>::Append(T &elem) {
  EnsureCapacity();
  data_[size_++] = elem;
}

[ 1, 2, 3, 4 ] template <typename T>
void DynamicArray<T>::Add(int index, T &elem) {
  if (size_ == capacity_) {
    capacity_ *= 2;
    T *newData = new T[capacity_];
    std::copy(data_, data + index, newData);
    std::copy(data + index, data + index + size_, newData);
    delete data_;
    data_ = newData;
  } else {
    std::copy(data_ + index + 1);
  }
  data_[index] = elem;
}

template <typename T>
void DynamicArray<T>::Delete(int index) {}

template <typename T>
bool DynamicArray<T>::IsEmpty() const {
  return size_ == 0;
}

template <typename T>
void DynamicArray<T>::EnsureCapacity() {
  if (size_ < capacity_) {
    return;
  }

  capacity_ *= 2;
  T *newData = new T[capacity_];
  std::copy_n(data_, size_, newData);
  delete _data;
  data_ = newData;
}
