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
#include <vector>

#include "comparable.hpp"

namespace cppds {

template <typename Comparable>
class BinaryHeap {
 public:
  explicit BinaryHeap(int capaicty = 10);
  explicit BinaryHeap(const std::vector<Comparable>& items);
  ~BinaryHeap();

  void Insert(Comparable& element);
  void Insert(Comparable&& element);
  bool IsEmpty() const;
  const Comparable& Min() const;
  void DeleteMin();
  void Clear();

 private:
  std::vector<Comparable> data_;
  size_t size_;

  void Heapify();
  void Down(size_t index);
  void Up(size_t index);
  void Swap(size_t i, size_t j);
};

/**
 * Public section
 */

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capcity) {
  data_ = std::vector<int>(10);
  size_ = 0;
}

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const std::vector<Comparable>& items) {
  data_ = items;
  size_ = items.size();
  Heapify();
}

template <typename Comparable>
BinaryHeap<Comparable>::~BinaryHeap() {}

template <typename Comparable>
bool BinaryHeap<Comparable>::IsEmpty() const {
  return size_ == 0;
}

template <typename Comparable>
void BinaryHeap<Comparable>::Insert(Comparable& element) {
  data_.push_back(element);
  Up(size_++);
}

template <typename Comparable>
void BinaryHeap<Comparable>::Insert(Comparable&& element) {
  Insert(element);
}

template <typename Comparable>
const Comparable& BinaryHeap<Comparable>::Min() const {
  return data_.at(0);
}

template <typename Comparable>
void BinaryHeap<Comparable>::DeleteMin() {
  Swap(--size_, 0);
  data_.pop_back();
  Down(0);
}

template <typename Comparable>
void BinaryHeap<Comparable>::Clear() {
  data_.clear();
  size_ = 0;
}

/**
 * Private section
 */

template <typename Comparable>
void BinaryHeap<Comparable>::Heapify() {
  for (int64_t i = size_ / 2; i >= 0; i--) {
    Down(i);
  }
}

template <typename Comparable>
void BinaryHeap<Comparable>::Down(size_t index) {
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

template <typename Comparable>
void BinaryHeap<Comparable>::Up(size_t index) {
  size_t p = index / 2;
  if (data_.at(p) > data_.at(index)) {
    Swap(p, index);
    Up(p);
  }
}

template <typename Comparable>
void BinaryHeap<Comparable>::Swap(size_t i, size_t j) {
  Comparable tmp = data_.at(i);
  data_.at(i) = data_.at(j);
  data_.at(j) = tmp;
}

}  // namespace cppds
