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
template <typename T>
class DoubleLinkedList : public LinkedList<T> {
 public:
  explicit DoubleLinkedList() : head(nullptr), tail(nullptr) {}

  ~DoubleLinkedList();

  size_t Size() const;

  void Append(T &&item) { Append(item); }

  void Append(T &item);

  void DeleteAt(size_t index);

  void AddAt(size_t index, T &item);

  void AddAt(size_t index, T &&item) { AddAt(index, item); }

  T &GetAt(size_t index) const { return GetNodeAt(index)->data; }

  T &GetHead() const {
    AssertNotEmpty();
    return head->data;
  }

  T &GetTail() const {
    AssertNotEmpty();
    return tail->data;
  }

  bool IsEmpty() const { return head == nullptr; }

 private:
  struct Node {
    T data;
    Node *prev;
    Node *next;

    Node(T &&p_data, Node *p_prev, Node *p_next) : data(std::move(p_data)), prev(p_prev), next(p_next) {}
  };

  Node *head;

  Node *tail;

  Node *GetNodeAt(size_t index) const;

  void AssertNotEmpty() const {
    if (IsEmpty()) throw std::out_of_range("out of bound");
  }

  Node *MakeNode(T &item, Node *prev, Node *next) const { return new Node{std::move(item), prev, next}; }
};

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  Node *ptr = head;
  while (ptr != nullptr) {
    Node *next = ptr->next;
    delete ptr;
    ptr = next;
  }
}

template <typename T>
size_t DoubleLinkedList<T>::Size() const {
  size_t size = 0;
  Node *ptr = head;
  while (ptr != nullptr) {
    ptr = ptr->next;
    size++;
  }
  return size;
}

template <typename T>
void DoubleLinkedList<T>::Append(T &item) {
  if (IsEmpty()) {
    tail = head = MakeNode(item, nullptr, nullptr);
    return;
  }

  tail = MakeNode(item, tail, nullptr);
}

template <typename T>
void DoubleLinkedList<T>::DeleteAt(size_t index) {
  AssertNotEmpty();
  if (index == 0) {
    Node *ptr = head;
    head = head->next;
    delete ptr;
    return;
  }

  Node *ptr = GetNodeAt(index);
  ptr->prev->next = ptr->next;
  delete ptr;
}

template <typename T>
void DoubleLinkedList<T>::AddAt(size_t index, T &item) {
  if (index == 0) {
    head = MakeNode(item, nullptr, head);
    return;
  }
  Node *ptr = GetNodeAt(index);
  ptr->prev->next = MakeNode(item, ptr->prev, ptr);
}

template <typename T>
DoubleLinkedList<T>::Node *DoubleLinkedList<T>::GetNodeAt(size_t index) const {
  AssertNotEmpty();

  Node *ptr = head;
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
