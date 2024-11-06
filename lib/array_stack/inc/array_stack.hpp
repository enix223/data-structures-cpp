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

#include "stack.hpp"

namespace cppds {

template <typename T>
class ArrayStack : public Stack<T> {
 public:
  explicit ArrayStack(size_t cap = 10) : _top(-1), _cap(cap) { _arr = new T[cap]; };

  ~ArrayStack() { delete[] _arr; }

  bool IsEmpty() const override { return _top == -1; }

  size_t Size() const override { return _top + 1; }

  void Push(T &&item) override { Push(item); }

  void Push(T &item) override {
    EnsureSize();
    _arr[++_top] = item;
  }

  T &Top() override {
    AssertNotEmpty();
    return _arr[_top];
  }

  void Pop() override {
    AssertNotEmpty();
    _top--;
  }

 private:
  size_t _top;
  T *_arr;
  size_t _cap;

  void AssertNotEmpty() {
    if (IsEmpty()) {
      throw std::out_of_range("stack is empty");
    }
  }

  void EnsureSize() {
    if (Size() <= _cap) {
      return;
    }

    size_t new_cap = _cap * 2;
    T *arr = new T[new_cap];
    std::copy(_arr, _arr + _cap, arr);
    delete[] _arr;
    _arr = arr;
    _cap = new_cap;
  }
};

}  // namespace cppds
