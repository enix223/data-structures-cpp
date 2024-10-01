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

#include "dynamic_array.hpp"

#include "gtest/gtest.h"

TEST(dynamic_array, should_allocate_with_capacity_success) {
  DynamicArray<int> arr = DynamicArray<int>(10);
  ASSERT_EQ(0, arr.Size());
  ASSERT_EQ(10, arr.Capacity());
}

TEST(dynamic_array, should_allocate_with_init_data_success) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 10);
  ASSERT_EQ(4, arr.Size());
  ASSERT_EQ(10, arr.Capacity());
}

TEST(dynamic_array, allocate_with_invalid_capacity_should_raise) {
  int init[]{1, 2, 3, 4};
  EXPECT_THROW({ DynamicArray<int> arr = DynamicArray<int>(init, 4, 2); }, std::invalid_argument);
}

TEST(dynamic_array, add_item_should_success) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 10);
  arr.Add(2, 5);
  ASSERT_EQ(5, arr.Size());
  ASSERT_EQ(1, arr.Get(0));
  ASSERT_EQ(2, arr.Get(1));
  ASSERT_EQ(5, arr.Get(2));
  ASSERT_EQ(3, arr.Get(3));
  ASSERT_EQ(4, arr.Get(4));
}

TEST(dynamic_array, add_at_beginning_index_should_success) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 10);
  arr.Add(0, 5);
  ASSERT_EQ(5, arr.Size());
  ASSERT_EQ(5, arr.Get(0));
  ASSERT_EQ(1, arr.Get(1));
  ASSERT_EQ(2, arr.Get(2));
  ASSERT_EQ(3, arr.Get(3));
  ASSERT_EQ(4, arr.Get(4));
}

TEST(dynamic_array, add_at_last_index_should_success) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 10);
  arr.Add(4, 5);
  ASSERT_EQ(5, arr.Size());
  ASSERT_EQ(1, arr.Get(0));
  ASSERT_EQ(2, arr.Get(1));
  ASSERT_EQ(3, arr.Get(2));
  ASSERT_EQ(4, arr.Get(3));
  ASSERT_EQ(5, arr.Get(4));
}

TEST(dynamic_array, add_item_should_success_when_expand_needed) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 4);
  arr.Add(2, 5);
  ASSERT_EQ(5, arr.Size());
  ASSERT_EQ(8, arr.Capacity());
  ASSERT_EQ(1, arr.Get(0));
  ASSERT_EQ(2, arr.Get(1));
  ASSERT_EQ(5, arr.Get(2));
  ASSERT_EQ(3, arr.Get(3));
  ASSERT_EQ(4, arr.Get(4));
}

TEST(dynamic_array, add_item_should_raise_when_index_out_of_bound) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 4);
  ASSERT_THROW({ arr.Add(5, 5); }, std::out_of_range);
  ASSERT_THROW({ arr.Add(-1, 5); }, std::out_of_range);
}

TEST(dynamic_array, delete_element_at_valid_index_should_success) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 4);
  arr.Delete(1);
  ASSERT_EQ(3, arr.Size());
  ASSERT_EQ(4, arr.Capacity());
  ASSERT_EQ(1, arr.Get(0));
  ASSERT_EQ(3, arr.Get(1));
  ASSERT_EQ(4, arr.Get(2));
}

TEST(dynamic_array, delete_element_at_last_index_should_success) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 4);
  arr.Delete(3);
  ASSERT_EQ(3, arr.Size());
  ASSERT_EQ(4, arr.Capacity());
  ASSERT_EQ(1, arr.Get(0));
  ASSERT_EQ(2, arr.Get(1));
  ASSERT_EQ(3, arr.Get(2));
}

TEST(dynamic_array, delete_element_at_invalid_index_should_failed) {
  int init[]{1, 2, 3, 4};
  DynamicArray<int> arr = DynamicArray<int>(init, 4, 4);
  ASSERT_THROW({ arr.Delete(10); }, std::out_of_range);
}