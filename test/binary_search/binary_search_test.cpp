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

TEST(binary_search, create_binary_search_should_be_ok) {
  vector<int> vect{1, 2, 5, 6};
  int res = BinarySearch<int>::find(vect, 2);
  ASSERT_EQ(res, 1);

  res = BinarySearch<int>::find(vect, 6);
  ASSERT_EQ(res, 3);

  res = BinarySearch<int>::find(vect, 0);
  ASSERT_EQ(res, -1);

  res = BinarySearch<int>::find(vect, 10);
  ASSERT_EQ(res, -1);

  res = BinarySearch<int>::find(vect, 3);
  ASSERT_EQ(res, -1);
}