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

#include "single_linked_list.hpp"

#include "gtest/gtest.h"

static std::unique_ptr<cppds::LinkedList<int>> createLinkedList() {
  auto linked_list = std::make_unique<cppds::LinkedList<int>>(cppds::LinkedList<int>{});
  linked_list->Append(10);
  linked_list->Append(11);
  linked_list->Append(12);
  return linked_list;
}

static void cleanup(cppds::LinkedList<int> *linked_list) { delete linked_list; }

TEST(linked_list, append_should_work) {
  auto linked_list = createLinkedList();
  auto v = linked_list->GetAt(0);
  EXPECT_EQ(10, v);
}

TEST(linked_list, is_empty_should_return_false_for_empty_list) {
  auto linked_list = cppds::LinkedList<int>{};
  EXPECT_TRUE(linked_list.IsEmpty());
}

TEST(linked_list, is_empty_should_return_true_for_non_empty_list) {
  auto linked_list = createLinkedList();
  EXPECT_FALSE(linked_list->IsEmpty());
}

TEST(linked_list, get_head_value_should_work) {
  auto linked_list = createLinkedList();
  auto v = linked_list->GetHead();
  EXPECT_EQ(10, v);
}

TEST(linked_list, get_tail_value_should_work) {
  auto linked_list = createLinkedList();
  auto v = linked_list->GetTail();
  EXPECT_EQ(12, v);
}

TEST(linked_list, delete_at_should_throw_when_index_out_of_bound) {
  cppds::LinkedList<int> linked_list{};
  EXPECT_THROW({ linked_list.DeleteAt(0); }, std::out_of_range);
}

TEST(linked_list, delete_at_should_work_for_valid_index) {
  auto linked_list = createLinkedList();
  EXPECT_NO_THROW({ linked_list->DeleteAt(0); });
  EXPECT_EQ(11, linked_list->GetHead());
  EXPECT_EQ(12, linked_list->GetTail());
}

TEST(linked_list, add_at_should_throw_when_index_out_of_bound) {
  cppds::LinkedList<int> linked_list{};
  EXPECT_THROW({ linked_list.AddAt(1, 99); }, std::out_of_range);
}

TEST(linked_list, add_at_should_work_for_valid_index) {
  auto linked_list = createLinkedList();
  EXPECT_NO_THROW({ linked_list->AddAt(0, 9); });
  EXPECT_EQ(9, linked_list->GetHead());
  EXPECT_EQ(12, linked_list->GetTail());

  EXPECT_NO_THROW({ linked_list->AddAt(3, 13); });
  EXPECT_EQ(9, linked_list->GetHead());
  EXPECT_EQ(12, linked_list->GetTail());

  EXPECT_NO_THROW({ linked_list->AddAt(2, 99); });
  EXPECT_EQ(99, linked_list->GetAt(2));
  EXPECT_EQ(11, linked_list->GetAt(3));
}

TEST(linked_list, add_at_should_work_when_index_eq_0_and_list_empty) {
  cppds::LinkedList<int> linked_list{};
  EXPECT_NO_THROW({ linked_list.AddAt(0, 9); });
  EXPECT_EQ(9, linked_list.GetHead());
}

TEST(linked_list, size_should_return_0_when_list_empty) {
  cppds::LinkedList<int> linked_list{};
  EXPECT_EQ(0, linked_list.Size());

  linked_list.Append(1);
  linked_list.Append(2);
  linked_list.Append(3);
  EXPECT_EQ(3, linked_list.Size());
}
