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

#include "heap.hpp"

#include "gtest/gtest.h"

TEST(heap, createa_heap_should_be_ok) {
  cppds::BinaryHeap<int> heap = cppds::BinaryHeap<int>(10);
  EXPECT_TRUE(heap.IsEmpty());

  heap.Insert(1);
  EXPECT_FALSE(heap.IsEmpty());
}

TEST(heap, min_should_return_correct_value) {
  cppds::BinaryHeap<int> heap = cppds::BinaryHeap<int>(std::vector<int>{3, 2, 1, 5, 0});
  ASSERT_EQ(heap.Min(), 0);
}

TEST(heap, clear_should_ok) {
  cppds::BinaryHeap<int> heap = cppds::BinaryHeap<int>(10);
  EXPECT_TRUE(heap.IsEmpty());

  heap.Insert(1);
  heap.Insert(2);
  heap.Clear();

  EXPECT_TRUE(heap.IsEmpty());

  heap = cppds::BinaryHeap<int>(std::vector<int>{1, 2, 3});
  EXPECT_FALSE(heap.IsEmpty());

  heap.Clear();
  EXPECT_TRUE(heap.IsEmpty());
}

TEST(heap, delete_should_remove_success) {
  cppds::BinaryHeap<int> heap = cppds::BinaryHeap<int>(std::vector<int>{5, 4, 3, 2, 1, 0});
  int min = heap.Min();
  EXPECT_EQ(min, 0);
  heap.DeleteMin();

  min = heap.Min();
  EXPECT_EQ(min, 1);
  heap.DeleteMin();

  min = heap.Min();
  EXPECT_EQ(min, 2);
  heap.DeleteMin();

  min = heap.Min();
  EXPECT_EQ(min, 3);
  heap.DeleteMin();

  min = heap.Min();
  EXPECT_EQ(min, 4);
  heap.DeleteMin();

  min = heap.Min();
  EXPECT_EQ(min, 5);
  heap.DeleteMin();
}
