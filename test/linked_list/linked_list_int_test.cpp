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

#include "double_linked_list.hpp"
#include "gtest/gtest.h"
#include "linked_list.hpp"
#include "single_linked_list.hpp"

template <typename T>
class LinkedListIntTest : public testing::Test {
  static_assert(std::is_base_of<cppds::LinkedList<int>, T>::value, "T must be subclass of cppds::LinkedList");

 public:
  T impl;
  void initWithValues() {
    impl.Append(10);
    impl.Append(11);
    impl.Append(12);
  }
};

TYPED_TEST_SUITE_P(LinkedListIntTest);

TYPED_TEST_P(LinkedListIntTest, AppendShouldWork) {
  auto v = this->impl.GetAt(0);
  EXPECT_EQ(10, v);
}

TYPED_TEST_P(LinkedListIntTest, IsEmptyShouldReturnFalseForEmptyList) { EXPECT_TRUE(this->impl.IsEmpty()); }

TYPED_TEST_P(LinkedListIntTest, IsEmptyShouldReturnTrueForNonEmptyList) {
  this->initWithValues();
  EXPECT_FALSE(this->impl.IsEmpty());
}

TYPED_TEST_P(LinkedListIntTest, GetHeadValueShouldWork) {
  this->initWithValues();
  EXPECT_EQ(10, this->impl.GetHead());
}

TYPED_TEST_P(LinkedListIntTest, GetTailValueShouldWork) {
  this->initWithValues();
  EXPECT_EQ(12, this->impl.GetTail());
}

TYPED_TEST_P(LinkedListIntTest, DeleteAtShouldThrowWhenIndexOutOfBound) {
  EXPECT_THROW({ this->impl.DeleteAt(0); }, std::out_of_range);
}

TYPED_TEST_P(LinkedListIntTest, DeleteAtShouldWorkForValidIndex) {
  this->initWithValues();
  EXPECT_NO_THROW({ this->impl.DeleteAt(0); });
  EXPECT_EQ(11, this->impl.GetHead());
  EXPECT_EQ(12, this->impl.GetTail());
}

TYPED_TEST_P(LinkedListIntTest, AddAtShouldThrowWhenIndexOutOfBound) {
  EXPECT_THROW({ this->impl.AddAt(1, 99); }, std::out_of_range);
}

TYPED_TEST_P(LinkedListIntTest, AddAtShouldWorkForValidIndex) {
  this->initWithValues();
  EXPECT_NO_THROW({ this->impl.AddAt(0, 9); });
  EXPECT_EQ(9, this->impl.GetHead());
  EXPECT_EQ(12, this->impl.GetTail());

  EXPECT_NO_THROW({ this->impl.AddAt(3, 13); });
  EXPECT_EQ(9, this->impl.GetHead());
  EXPECT_EQ(12, this->impl.GetTail());

  EXPECT_NO_THROW({ this->impl.AddAt(2, 99); });
  EXPECT_EQ(99, this->impl.GetAt(2));
  EXPECT_EQ(11, this->impl.GetAt(3));
}

TYPED_TEST_P(LinkedListIntTest, AddAtShouldWorkWhenIndexEq0AndListEmpty) {
  EXPECT_NO_THROW({ this->impl.AddAt(0, 9); });
  EXPECT_EQ(9, this->impl.GetHead());
}

TYPED_TEST_P(LinkedListIntTest, SizeShouldReturn0WhenListEmpty) {
  EXPECT_EQ(0, this->impl.Size());
  this->impl.Append(1);
  this->impl.Append(2);
  this->impl.Append(3);
  EXPECT_EQ(3, this->impl.Size());
}

REGISTER_TYPED_TEST_SUITE_P(LinkedListIntTest,
                            AppendShouldWork,                         //
                            IsEmptyShouldReturnFalseForEmptyList,     //
                            IsEmptyShouldReturnTrueForNonEmptyList,   //
                            GetHeadValueShouldWork,                   //
                            GetTailValueShouldWork,                   //
                            DeleteAtShouldThrowWhenIndexOutOfBound,   //
                            DeleteAtShouldWorkForValidIndex,          //
                            AddAtShouldThrowWhenIndexOutOfBound,      //
                            AddAtShouldWorkForValidIndex,             //
                            AddAtShouldWorkWhenIndexEq0AndListEmpty,  //
                            SizeShouldReturn0WhenListEmpty);

using LinkedListTypes = testing::Types<cppds::SingleLinkedList<int>, cppds::DoubleLinkedList<int>>;
INSTANTIATE_TYPED_TEST_SUITE_P(LinkedListIntTestInstance, LinkedListIntTest, LinkedListTypes);