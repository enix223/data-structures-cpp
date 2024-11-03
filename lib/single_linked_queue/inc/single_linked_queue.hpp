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

#include "queue.hpp"
#include "single_linked_list.hpp"

namespace cppds {

template <typename T>
class SingleLinkedQueue : public cppds::Queue<T>, private cppds::SingleLinkedList<T> {
 public:
  void Enqueue(T &&item) override { cppds::SingleLinkedList<T>::Append(item); }

  void Enqueue(T &item) override { cppds::SingleLinkedList<T>::Append(item); }

  bool IsEmpty() const override { return cppds::SingleLinkedList<T>::IsEmpty(); }

  size_t Size() const override { return cppds::SingleLinkedList<T>::Size(); }

  T &Front() override { return cppds::SingleLinkedList<T>::GetHead(); }

  T &Back() override { return cppds::SingleLinkedList<T>::GetTail(); }

  void Dequeue() override { cppds::SingleLinkedList<T>::DeleteAt(0); }
};

}  // namespace cppds
