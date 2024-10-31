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

namespace cppds {
template <typename T>
class LinkedList {
 public:
  // Return the size of the linked list
  virtual size_t Size() const = 0;

  // Return linked list empty or not
  virtual bool IsEmpty() const = 0;

  // Append an item to the end of the linked list, accept rvalue.
  virtual void Append(T&& item) = 0;

  // Append an item to the end of the linked list, accept lvalue.
  virtual void Append(T& item) = 0;

  virtual void DeleteAt(size_t index) = 0;

  virtual void AddAt(size_t index, T& item) = 0;

  virtual void AddAt(size_t index, T&& item) = 0;

  virtual T& GetAt(size_t index) const = 0;

  virtual T& GetHead() const = 0;

  virtual T& GetTail() const = 0;
};
}  // namespace cppds
