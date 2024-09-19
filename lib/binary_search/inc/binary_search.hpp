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

#include <vector>

template <typename Comparable>
class BinarySearch {
 public:
  static int Find(std::vector<Comparable> &data, Comparable &&elem);
  static int FindBalance(std::vector<Comparable> &data, Comparable &&elem);
  static int FindLeftMost(std::vector<Comparable> &data, Comparable &&elem);
  static int FindRightMost(std::vector<Comparable> &data, Comparable &&elem);
};

template <typename Comparable>
int BinarySearch<Comparable>::Find(std::vector<Comparable> &data, Comparable &&elem) {
  int i = 0, j = data.size() - 1;
  while (i <= j) {
    int m = (i + j) >> 1;
    if (elem < data.at(m)) {
      j = m - 1;
    } else if (elem > data.at(m)) {
      i = m + 1;
    } else {
      return m;
    }
  }
  return -i - 1;
}

template <typename Comparable>
int BinarySearch<Comparable>::FindBalance(std::vector<Comparable> &data, Comparable &&elem) {
  int i = 0, j = data.size();
  while (j - i > 1) {
    int m = (i + j) >> 1;
    if (elem < data.at(m)) {
      j = m;
    } else {
      i = m;
    }
  }
  if (elem == data.at(i)) {
    return i;
  }
  return -i - 1;
}

template <typename Comparable>
int BinarySearch<Comparable>::FindLeftMost(std::vector<Comparable> &data, Comparable &&elem) {
  int i = 0, j = data.size() - 1;
  while (i <= j) {
    int m = (i + j) >> 1;
    if (elem <= data.at(m)) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }
  return i;
}

template <typename Comparable>
int BinarySearch<Comparable>::FindRightMost(std::vector<Comparable> &data, Comparable &&elem) {
  int i = 0, j = data.size() - 1;
  while (i <= j) {
    int m = (i + j) >> 1;
    if (elem >= data.at(m)) {
      i = m + 1;
    } else {
      j = m - 1;
    }
  }
  return j;
}
