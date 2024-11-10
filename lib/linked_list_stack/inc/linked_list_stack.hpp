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

#include <stdexcept>

#include "stack.hpp"

namespace cppds {

template <typename T>
class LinkedListStack : public Stack<T> {
 public:
  explicit LinkedListStack() : _top(nullptr), _size(0) {};

  bool IsEmpty() const override { return _size == 0; }

  size_t Size() const override { return _size; }

  void Push(T &&item) override { Push(item); }

  void Push(T &item) override {
    _top = new Node{std::move(item), _top};
    _size++;
  }

  T &Top() override {
    AssertNotEmpty();
    return _top->value;
  }

  void Pop() override {
    AssertNotEmpty();
    Node *prev = _top->prev;
    delete _top;
    _top = prev;
  }

 private:
  struct Node {
    T value;
    Node *prev;
  };

  Node *_top;
  size_t _size;

  void AssertNotEmpty() {
    if (IsEmpty()) {
      throw std::out_of_range("stack is empty");
    }
  }
};

}  // namespace cppds
