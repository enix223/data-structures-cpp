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
#include <vector>

namespace cppds {

template <typename T>
class LinkedList {
 public:
  explicit LinkedList();

  ~LinkedList();

  void Append(T* item);

  void DeleteAt(size_t index);

  void AddAt(size_t index, T* item);

  T* GetAt(size_t index) { return GetNodeAt(index)->data; };

  T* GetHead() { return head->next == nullptr ? nullptr : head->next->data; };

  T* GetTail() { return GetTailNode()->data; };

 private:
  struct Node {
    T* data;
    Node* next;
  };

  Node* head;

  Node* GetTailNode();

  Node* GetNodeAt(size_t index);
};

template <typename T>
inline LinkedList<T>::LinkedList() {
  head = new Node{nullptr, nullptr};
}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node* ptr = head;
  Node* next = head->next;
  while (ptr != nullptr) {
    next = ptr->next;
    delete ptr;
    ptr = next;
  }
}

template <typename T>
inline void LinkedList<T>::Append(T* item) {
  Node* tail = GetTailNode();
  tail->next = new Node{item, nullptr};
}

template <typename T>
void LinkedList<T>::DeleteAt(size_t index) {
  Node* prev = index == 0 ? head : GetNodeAt(index - 1);
  Node* ptr = prev->next;
  prev->next = prev->next->next;
  delete ptr;
}

template <typename T>
void LinkedList<T>::AddAt(size_t index, T* item) {
  Node* ptr = GetNodeAt(index);
  ptr->next = new Node{item, nullptr};
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>::GetTailNode() {
  Node* tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  return tail;
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>::GetNodeAt(size_t index) {
  Node* ptr = head->next;
  if (ptr == nullptr) {
    throw std::out_of_range("index out of bound");
  }

  for (size_t i = 0; i < index; i++) {
    ptr = ptr->next;
    if (ptr == nullptr) {
      throw std::out_of_range("index out of bound");
    }
  }

  return ptr;
}

}  // namespace cppds
