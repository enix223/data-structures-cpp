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

#include "double_linked_list.hpp"
#include "queue.hpp"

namespace cppds {

template <typename T>
class DoubleLinkedQueue : public cppds::Queue<T>, private cppds::DoubleLinkedList<T> {
 public:
  void Enqueue(T &&item) override { cppds::DoubleLinkedList<T>::Append(item); }

  void Enqueue(T &item) override { cppds::DoubleLinkedList<T>::Append(item); }

  bool IsEmpty() const override { return cppds::DoubleLinkedList<T>::IsEmpty(); }

  size_t Size() const override { return cppds::DoubleLinkedList<T>::Size(); }

  T &Front() override { return cppds::DoubleLinkedList<T>::GetHead(); }

  T &Back() override { return cppds::DoubleLinkedList<T>::GetTail(); }

  void Dequeue() override { cppds::DoubleLinkedList<T>::DeleteAt(0); }
};

}  // namespace cppds
