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

class Value {
 public:
  explicit Value(const size_t size) {
    internal_values = new int[size];
    m_size = size;
  }

  // copy constructor
  Value(const Value &another) {
    m_size = another.m_size;
    internal_values = new int[m_size];
    memcpy(internal_values, another.internal_values, m_size);
  }

  // move constructor
  Value(Value &&another) {
    m_size = another.m_size;
    internal_values = another.internal_values;
    another.internal_values = nullptr;
  }

  Value &operator=(Value &&another) {
    if (this == &another) {
      return *this;
    }

    delete[] internal_values;
    m_size = another.m_size;
    internal_values = another.internal_values;
    return *this;
  }

  ~Value() { delete[] internal_values; }

  size_t GetSize() const { return m_size; };

 private:
  size_t m_size;
  int *internal_values;
};

template <typename T>
class LinkedListValueTest : public testing::Test {
  static_assert(std::is_base_of<cppds::LinkedList<Value>, T>::value, "T must be subclass of cppds::LinkedList");

 public:
  T impl;
  void initWithValues() {
    impl.Append(Value{10});
    impl.Append(Value{11});
    impl.Append(Value{12});
  }
};

TYPED_TEST_SUITE_P(LinkedListValueTest);

TYPED_TEST_P(LinkedListValueTest, AppendShouldWork) {
  this->initWithValues();
  auto v = this->impl.GetAt(0);
  auto s = v.GetSize();
  EXPECT_EQ(10, s);
}

TYPED_TEST_P(LinkedListValueTest, IsEmptyShouldReturnFalseForEmptyList) { EXPECT_TRUE(this->impl.IsEmpty()); }

TYPED_TEST_P(LinkedListValueTest, IsEmptyShouldReturnTrueForNonEmptyList) {
  this->initWithValues();
  EXPECT_FALSE(this->impl.IsEmpty());
}

TYPED_TEST_P(LinkedListValueTest, GetHeadValueShouldWork) {
  this->initWithValues();
  auto v = this->impl.GetHead();
  EXPECT_EQ(10, v.GetSize());
}

TYPED_TEST_P(LinkedListValueTest, GetTailValueShouldWork) {
  this->initWithValues();
  auto v = this->impl.GetTail();
  EXPECT_EQ(12, v.GetSize());
}

TYPED_TEST_P(LinkedListValueTest, DeleteAtShouldThrowWhenIndexOutOfBound) {
  EXPECT_THROW({ this->impl.DeleteAt(0); }, std::out_of_range);
}

TYPED_TEST_P(LinkedListValueTest, DeleteAtShouldWorkForValidIndex) {
  this->initWithValues();
  EXPECT_NO_THROW({ this->impl.DeleteAt(0); });
  EXPECT_EQ(11, this->impl.GetHead().GetSize());
  EXPECT_EQ(12, this->impl.GetTail().GetSize());
}

TYPED_TEST_P(LinkedListValueTest, AddAtShouldThrowWhenIndexOutOfBound) {
  EXPECT_THROW({ this->impl.AddAt(1, Value{99}); }, std::out_of_range);
}

TYPED_TEST_P(LinkedListValueTest, AddAtShouldWorkForValidIndex) {
  this->initWithValues();
  EXPECT_NO_THROW({ this->impl.AddAt(0, Value{9}); });
  EXPECT_EQ(9, this->impl.GetHead().GetSize());
  EXPECT_EQ(12, this->impl.GetTail().GetSize());

  EXPECT_NO_THROW({ this->impl.AddAt(3, Value{13}); });
  EXPECT_EQ(9, this->impl.GetHead().GetSize());
  EXPECT_EQ(12, this->impl.GetTail().GetSize());

  EXPECT_NO_THROW({ this->impl.AddAt(2, Value{99}); });
  EXPECT_EQ(99, this->impl.GetAt(2).GetSize());
  EXPECT_EQ(11, this->impl.GetAt(3).GetSize());
}

TYPED_TEST_P(LinkedListValueTest, AddAtShouldWorkWhenIndexEq0AndListEmpty) {
  EXPECT_NO_THROW({ this->impl.AddAt(0, Value{9}); });
  EXPECT_EQ(9, this->impl.GetHead().GetSize());
}

TYPED_TEST_P(LinkedListValueTest, SizeShouldReturn0WhenListEmpty) {
  EXPECT_EQ(0, this->impl.Size());

  this->impl.Append(Value{1});
  this->impl.Append(Value{2});
  this->impl.Append(Value{3});
  EXPECT_EQ(3, this->impl.Size());
}

REGISTER_TYPED_TEST_SUITE_P(LinkedListValueTest,                      //
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
                            SizeShouldReturn0WhenListEmpty            //
);

using LinkedListTypes = testing::Types<cppds::SingleLinkedList<Value>, cppds::DoubleLinkedList<Value>>;
INSTANTIATE_TYPED_TEST_SUITE_P(LinkedListValueTestInstance, LinkedListValueTest, LinkedListTypes);
