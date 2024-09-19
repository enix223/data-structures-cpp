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

using std::vector;

template <typename Comparable>
class BinaryHeap {
 private:
  vector<Comparable> data;
  int size;

  void heapify();
  void down(int index);
  void up(int index);
  void swap(int i, int j);

 public:
  explicit BinaryHeap(int capaicty = 10);
  explicit BinaryHeap(const vector<Comparable>& items);

  void insert(Comparable& element);
  void insert(Comparable&& element);
  bool isEmpty() const;
  const Comparable& min() const;
  void deleteMin();
  void clear();
};

/**
 * Public section
 */

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capcity) {
  data = std::vector<int>(10);
  size = 0;
}

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable>& items) {
  data = items;
  size = items.size();
  heapify();
}

template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const {
  return size == 0;
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(Comparable& element) {
  data.push_back(element);
  up(size++);
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(Comparable&& element) {
  insert(element);
}

template <typename Comparable>
const Comparable& BinaryHeap<Comparable>::min() const {
  return data.at(0);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin() {
  swap(--size, 0);
  data.pop_back();
  down(0);
}

template <typename Comparable>
void BinaryHeap<Comparable>::clear() {
  data.clear();
  size = 0;
}

/**
 * Private section
 */

template <typename Comparable>
void BinaryHeap<Comparable>::heapify() {
  for (int i = size / 2; i >= 0; i--) {
    down(i);
  }
}

template <typename Comparable>
void BinaryHeap<Comparable>::down(int index) {
  int l = index * 2 + 1;
  int r = l + 1;
  int min = index;
  if (l < size && data.at(l) < data.at(min)) {
    min = l;
  }
  if (r < size && data.at(r) < data.at(min)) {
    min = r;
  }
  if (min == index) {
    return;
  }
  swap(min, index);
  down(min);
}

template <typename Comparable>
void BinaryHeap<Comparable>::up(int index) {
  int p = index / 2;
  if (data.at(p) > data.at(index)) {
    swap(p, index);
    up(p);
  }
}

template <typename Comparable>
void BinaryHeap<Comparable>::swap(int i, int j) {
  int tmp = data.at(i);
  data.at(i) = data.at(j);
  data.at(j) = tmp;
}
