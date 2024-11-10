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

#include <concepts>
#include <cstdint>
#include <vector>

#include "comparable.hpp"

namespace cppds {

template <cppds::Comparable T>
class BinaryHeap {
 public:
  explicit BinaryHeap(int capaicty = 10);
  explicit BinaryHeap(const std::vector<T>& items);
  ~BinaryHeap();

  void Insert(T& element);
  void Insert(T&& element);
  bool IsEmpty() const;
  const T& Min() const;
  void DeleteMin();
  void Clear();

 private:
  std::vector<T> data_;
  size_t size_;

  void Heapify();
  void Down(size_t index);
  void Up(size_t index);
  void Swap(size_t i, size_t j);
};

/**
 * Public section
 */

template <cppds::Comparable T>
BinaryHeap<T>::BinaryHeap(int capcity) {
  data_ = std::vector<int>(10);
  size_ = 0;
}

template <cppds::Comparable T>
BinaryHeap<T>::BinaryHeap(const std::vector<T>& items) {
  data_ = items;
  size_ = items.size();
  Heapify();
}

template <cppds::Comparable T>
BinaryHeap<T>::~BinaryHeap() {}

template <cppds::Comparable T>
bool BinaryHeap<T>::IsEmpty() const {
  return size_ == 0;
}

template <cppds::Comparable T>
void BinaryHeap<T>::Insert(T& element) {
  data_.push_back(element);
  Up(size_++);
}

template <cppds::Comparable T>
void BinaryHeap<T>::Insert(T&& element) {
  Insert(element);
}

template <cppds::Comparable T>
const T& BinaryHeap<T>::Min() const {
  return data_.at(0);
}

template <cppds::Comparable T>
void BinaryHeap<T>::DeleteMin() {
  Swap(--size_, 0);
  data_.pop_back();
  Down(0);
}

template <cppds::Comparable T>
void BinaryHeap<T>::Clear() {
  data_.clear();
  size_ = 0;
}

/**
 * Private section
 */

template <cppds::Comparable T>
void BinaryHeap<T>::Heapify() {
  for (int64_t i = size_ / 2; i >= 0; i--) {
    Down(i);
  }
}

template <cppds::Comparable T>
void BinaryHeap<T>::Down(size_t index) {
  size_t l = index * 2 + 1;
  size_t r = l + 1;
  size_t min = index;
  if (l < size_ && data_.at(l) < data_.at(min)) {
    min = l;
  }
  if (r < size_ && data_.at(r) < data_.at(min)) {
    min = r;
  }
  if (min == index) {
    return;
  }
  Swap(min, index);
  Down(min);
}

template <cppds::Comparable T>
void BinaryHeap<T>::Up(size_t index) {
  size_t p = index / 2;
  if (data_.at(p) > data_.at(index)) {
    Swap(p, index);
    Up(p);
  }
}

template <cppds::Comparable T>
void BinaryHeap<T>::Swap(size_t i, size_t j) {
  T tmp = data_.at(i);
  data_.at(i) = data_.at(j);
  data_.at(j) = tmp;
}

}  // namespace cppds
