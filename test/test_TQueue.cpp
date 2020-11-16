#include "Queue.h"

#include "../gtest/gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> bf(3));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
    ASSERT_ANY_THROW(TQueue<int> A(-1));
}

TEST(TQueue, can_copy_queue)
{
    TQueue<int> A(10);
    ASSERT_NO_THROW(TQueue<int> B(A));
}

TEST(TQueue, can_push_if_not_full)
{
    TQueue<int> A(1);
    ASSERT_NO_THROW(A.Push(2));
}

TEST(TQueue, can_get_elem_if_empty)
{
    TQueue<int> A(1);
    A.Push(1);
    A.Get();
    ASSERT_ANY_THROW(A.Get());
}

TEST(TQueue, can_get_elem_if_not_empty)
{
    TQueue<int> A(1);
    A.Push(1);
    ASSERT_NO_THROW(A.Get());
}

TEST(TQueue, can_get_elem)
{
    TQueue<int> A(2);
    A.Push(1);
    A.Push(2);
    A.Get();
    ASSERT_EQ(2, A.Get());
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
    TQueue<int> A(1);
    A.Push(2);
    TQueue<int> B(A);
    ASSERT_EQ(A.Get(), B.Get());
}

TEST(TQueue, correct_order_of_return_values)
{
    TQueue <int> A(3);
    A.Push(5);
    A.Push(4);
    A.Push(3);
    ASSERT_EQ(5, A.Get());
    ASSERT_EQ(4, A.Get());
    ASSERT_EQ(3, A.Get());
}

TEST(TQueue, can_push_and_get)
{
    TQueue<int> A(10);
    A.Push(1);

    ASSERT_EQ(1, A.Get());
}

TEST(TQueue, can_push_when_full)
{
    TQueue<int> A(1);
    A.Push(1);
    ASSERT_NO_THROW(A.Push(2));
}

TEST(TQueue, can_get_min_elem)
{
    TQueue <int> A(3);
    A.Push(5);
    A.Push(4);
    A.Push(3);
    ASSERT_EQ(3, A.MinElem());
}

TEST(TQueue, can_get_max_elem)
{
    TQueue <int> A(3);
    A.Push(5);
    A.Push(4);
    A.Push(3);
    ASSERT_EQ(5, A.MaxElem());
}