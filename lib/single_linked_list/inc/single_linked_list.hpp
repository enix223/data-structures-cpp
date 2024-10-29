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
#include <utility>

#include "linked_list.hpp"

namespace cppds {

// SingleLinkedList represent a linked list with only a header point to the
// start of the list.
//
// ::Layout::
//
// head ->[ node1 ]  +->[ node1 ]  +->[ node1 ]
//        [-------]  |  [-------]  |  [-------]
//        [ data  ]  |  [ data  ]  |  [ data  ]
//        [ next  ]--+  [ next  ]--+  [ next  ]-->|| nullptr
//
template <typename T>
class SingleLinkedList : public LinkedList<T> {
 public:
  // Default construtor will initialize a linked list with a head pointer
  // pointing to null.
  explicit SingleLinkedList() : head(nullptr) {}

  ~SingleLinkedList();

  // Return the size of the linked list
  size_t Size() const;

  // Return linked list empty or not
  bool IsEmpty() const { return head == nullptr; }

  // Append an item to the end of the linked list, accept rvalue.
  void Append(T&& item) { Append(item); }

  // Append an item to the end of the linked list, accept lvalue.
  void Append(T& item);

  void DeleteAt(size_t index);

  void AddAt(size_t index, T& item);

  void AddAt(size_t index, T&& item) { AddAt(index, item); }

  T& GetAt(size_t index) const { return GetNodeAt(index)->data; }

  T& GetHead() const { return head == nullptr ? throw std::out_of_range("out of bound") : head->data; }

  T& GetTail() const { return GetTailNode()->data; }

 private:
  struct Node {
    T data;
    Node* next;

    Node(T&& p_data, Node* p_next) : data(std::move(p_data)), next(p_next) {}
  };

  Node* head;

  Node* GetTailNode() const;

  Node* GetNodeAt(size_t index) const;

  void AssertNotEmpty() const {
    if (IsEmpty()) throw std::out_of_range("out of bound");
  }

  Node* MakeNode(T& item, Node* next) const { return new Node{std::move(item), next}; }
};

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
  Node* ptr = head;
  while (ptr != nullptr) {
    Node* next = ptr->next;
    delete ptr;
    ptr = next;
  }
}

template <typename T>
size_t SingleLinkedList<T>::Size() const {
  size_t s = 0;
  Node* ptr = head;
  while (ptr != nullptr) {
    ptr = ptr->next;
    s++;
  }
  return s;
}

template <typename T>
void SingleLinkedList<T>::Append(T& item) {
  if (IsEmpty()) {
    head = MakeNode(item, nullptr);
    return;
  }
  Node* tail = GetTailNode();
  tail->next = MakeNode(item, nullptr);
}

template <typename T>
void SingleLinkedList<T>::DeleteAt(size_t index) {
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
void SingleLinkedList<T>::AddAt(size_t index, T& item) {
  if (index == 0) {
    head = MakeNode(item, head);
    return;
  }
  Node* prev = GetNodeAt(index - 1);
  prev->next = MakeNode(item, prev->next);
}

template <typename T>
SingleLinkedList<T>::Node* SingleLinkedList<T>::GetTailNode() const {
  AssertNotEmpty();

  Node* tail = head;
  while (tail != nullptr && tail->next != nullptr) {
    tail = tail->next;
  }
  return tail;
}

template <typename T>
SingleLinkedList<T>::Node* SingleLinkedList<T>::GetNodeAt(size_t index) const {
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
