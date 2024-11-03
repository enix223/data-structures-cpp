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

#include "double_linked_queue.hpp"
#include "gtest/gtest.h"
#include "queue.hpp"
#include "single_linked_queue.hpp"

template <typename T>
class QueueIntTest : public testing::Test {
  static_assert(std::is_base_of<cppds::Queue<int>, T>::value, "T must be subclass of cppds::Queue");

 public:
  T impl;
};

TYPED_TEST_SUITE_P(QueueIntTest);

TYPED_TEST_P(QueueIntTest, EqueneRValueShouldWork) {
  this->impl.Enqueue(1);
  EXPECT_EQ(1, this->impl.Front());
}

TYPED_TEST_P(QueueIntTest, EqueneLValueShouldWork) {
  int i = 9876;
  this->impl.Enqueue(i);
  EXPECT_EQ(i, this->impl.Front());
}

TYPED_TEST_P(QueueIntTest, EmptyQueueIsEmptyShouldReturnTrue) { EXPECT_TRUE(this->impl.IsEmpty()); }

TYPED_TEST_P(QueueIntTest, NonEmptyQueueIsEmptyShouldReturnFalse) {
  this->impl.Enqueue(1);
  EXPECT_FALSE(this->impl.IsEmpty());
}

TYPED_TEST_P(QueueIntTest, SizeShouldReturnCorrectResult) {
  this->impl.Enqueue(1);
  EXPECT_EQ(1, this->impl.Size());
}

TYPED_TEST_P(QueueIntTest, EnqueueLotOfItemsShouldWork) {
  size_t size = 10000;
  for (int i = 0; i < size; i++) {
    this->impl.Enqueue(i);
  }
  EXPECT_EQ(size, this->impl.Size());
}

REGISTER_TYPED_TEST_SUITE_P(QueueIntTest, EqueneLValueShouldWork, EqueneRValueShouldWork,
                            EmptyQueueIsEmptyShouldReturnTrue, NonEmptyQueueIsEmptyShouldReturnFalse,
                            EnqueueLotOfItemsShouldWork, SizeShouldReturnCorrectResult);

using QueueIntTypes = testing::Types<cppds::SingleLinkedQueue<int>, cppds::DoubleLinkedQueue<int>>;
INSTANTIATE_TYPED_TEST_SUITE_P(QueueIntTestInstance, QueueIntTest, QueueIntTypes);
