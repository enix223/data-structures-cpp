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

#include "linked_list.hpp"

#include "gtest/gtest.h"

static cppds::LinkedList<int> *createLinkedList() {
  auto linkedList = new cppds::LinkedList<int>{};
  int *a = new int{10}, *b = new int{11}, *c = new int{12};
  linkedList->Append(a);
  linkedList->Append(b);
  linkedList->Append(c);
  return linkedList;
}

TEST(linked_list, append_should_work) {
  auto linkedList = createLinkedList();
  auto v = linkedList->GetAt(0);
  EXPECT_EQ(10, *v);
}

TEST(linked_list, get_head_value_should_work) {
  auto linkedList = createLinkedList();
  auto v = linkedList->GetHead();
  EXPECT_EQ(10, *v);
}

TEST(linked_list, get_tail_value_should_work) {
  auto linkedList = createLinkedList();
  auto v = linkedList->GetTail();
  EXPECT_EQ(12, *v);
}
