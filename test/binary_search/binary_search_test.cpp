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
#include "binary_search.hpp"

#include <vector>

#include "gtest/gtest.h"

using namespace std;

TEST(binary_search, find_should_work_fine_for_exist_and_non_exist_element) {
  vector<int> vect{1, 2, 5, 6};
  int res = BinarySearch<int>::Find(vect, 2);
  ASSERT_EQ(res, 1);

  res = BinarySearch<int>::Find(vect, 6);
  ASSERT_EQ(res, 3);

  res = BinarySearch<int>::Find(vect, 0);
  ASSERT_EQ(res, -1);

  res = BinarySearch<int>::Find(vect, 10);
  ASSERT_EQ(res, -5);

  res = BinarySearch<int>::Find(vect, 3);
  ASSERT_EQ(res, -3);
}

TEST(binary_search, find_balance_should_work_fine_for_exist_and_non_exist_element) {
  vector<int> vect{1, 2, 5, 6};
  int res = BinarySearch<int>::FindBalance(vect, 2);
  ASSERT_EQ(res, 1);

  res = BinarySearch<int>::FindBalance(vect, 6);
  ASSERT_EQ(res, 3);

  res = BinarySearch<int>::FindBalance(vect, 0);
  ASSERT_EQ(res, -1);

  res = BinarySearch<int>::FindBalance(vect, 10);
  ASSERT_EQ(res, -5);

  res = BinarySearch<int>::FindBalance(vect, 3);
  ASSERT_EQ(res, -3);
}

TEST(binary_search, find_left_most_should_work_fine_for_exist_and_non_exist_element) {
  vector<int> vect{1, 2, 2, 2, 5, 5, 8, 10};
  int res = BinarySearch<int>::FindLeftMost(vect, 2);
  ASSERT_EQ(res, 1);

  res = BinarySearch<int>::FindLeftMost(vect, 1);
  ASSERT_EQ(res, 0);

  res = BinarySearch<int>::FindLeftMost(vect, 5);
  ASSERT_EQ(res, 4);

  res = BinarySearch<int>::FindLeftMost(vect, 10);
  ASSERT_EQ(res, 7);

  res = BinarySearch<int>::FindLeftMost(vect, 6);
  ASSERT_EQ(res, 6);

  res = BinarySearch<int>::FindLeftMost(vect, 0);
  ASSERT_EQ(res, 0);

  res = BinarySearch<int>::FindLeftMost(vect, 12);
  ASSERT_EQ(res, 8);
}

TEST(binary_search, find_right_most_should_work_fine_for_exist_and_non_exist_element) {
  vector<int> vect{1, 2, 2, 2, 5, 5, 8, 10};
  int res = BinarySearch<int>::FindRightMost(vect, 2);
  ASSERT_EQ(res, 3);

  res = BinarySearch<int>::FindRightMost(vect, 1);
  ASSERT_EQ(res, 0);

  res = BinarySearch<int>::FindRightMost(vect, 5);
  ASSERT_EQ(res, 5);

  res = BinarySearch<int>::FindRightMost(vect, 10);
  ASSERT_EQ(res, 7);

  res = BinarySearch<int>::FindRightMost(vect, 3);
  ASSERT_EQ(res, 3);

  res = BinarySearch<int>::FindRightMost(vect, 6);
  ASSERT_EQ(res, 5);

  res = BinarySearch<int>::FindRightMost(vect, 0);
  ASSERT_EQ(res, -1);

  res = BinarySearch<int>::FindRightMost(vect, 12);
  ASSERT_EQ(res, 7);
}
