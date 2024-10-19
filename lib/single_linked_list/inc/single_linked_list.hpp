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
#include <memory>
#include <stdexcept>
#include <vector>

namespace cppds {

template <typename T>
class LinkedList {
 public:
  explicit LinkedList() : head(nullptr) {}

  ~LinkedList();

  size_t Size() const;

  bool IsEmpty() const { return head == nullptr; }

  void Append(const T&& item);

  void DeleteAt(size_t index);

  void AddAt(size_t index, const T&& item);

  const T& GetAt(size_t index) const { return *(GetNodeAt(index)->data); }

  const T& GetHead() const { return head == nullptr ? throw std::out_of_range("out of bound") : *(head->data); }

  const T& GetTail() const { return *(GetTailNode()->data); }

 private:
  struct Node {
    std::shared_ptr<T> data;
    Node* next;
  };

  Node* head;

  Node* GetTailNode() const;

  Node* GetNodeAt(size_t index) const;

  void AssertNotEmpty() const {
    if (IsEmpty()) throw std::out_of_range("out of bound");
  }
};

template <typename T>
LinkedList<T>::~LinkedList() {
  Node* ptr = head;
  while (ptr != nullptr) {
    Node* next = ptr->next;
    delete ptr;
    ptr = next;
  }
}

template <typename T>
size_t LinkedList<T>::Size() const {
  size_t s = 0;
  Node* ptr = head;
  while (ptr != nullptr) {
    ptr = ptr->next;
    s++;
  }
  return s;
}

template <typename T>
void LinkedList<T>::Append(const T&& item) {
  if (IsEmpty()) {
    head = new Node{std::make_shared<T>(item), nullptr};
    return;
  }
  Node* tail = GetTailNode();
  tail->next = new Node{std::make_shared<T>(item), nullptr};
}

template <typename T>
void LinkedList<T>::DeleteAt(size_t index) {
  AssertNotEmpty();
  if (index == 0) {
    Node* ptr = head;
    head = head->next;
    delete ptr;
    return;
  }

  Node* prev = GetNodeAt(index - 1);
  Node* ptr = prev->next;
  prev->next = ptr->next;
  delete ptr;
}

template <typename T>
void LinkedList<T>::AddAt(size_t index, const T&& item) {
  if (index == 0) {
    head = new Node{std::make_shared<T>(item), head};
    return;
  }
  Node* prev = GetNodeAt(index - 1);
  prev->next = new Node{std::make_shared<T>(item), prev->next};
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>::GetTailNode() const {
  AssertNotEmpty();

  Node* tail = head;
  while (tail != nullptr && tail->next != nullptr) {
    tail = tail->next;
  }
  return tail;
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>::GetNodeAt(size_t index) const {
  AssertNotEmpty();

  Node* ptr = head;
  size_t i = 0;
  while (i < index && ptr != nullptr) {
    i++;
    ptr = ptr->next;
  }
  if (i != index || ptr == nullptr) {
    throw std::out_of_range("index out of bound");
  }
  return ptr;
}

}  // namespace cppds
