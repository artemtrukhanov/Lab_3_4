#include "Stack.h"

#include "../gtest/gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(TStack<int> bf(3));
}

TEST(TStack, throws_when_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(TStack<int> S(-10));
}

TEST(TStack, can_add_a_new_element)
{
    TStack<int> A(3);

    ASSERT_NO_THROW(A.Push(5));
}

TEST(TStack, can_copy_stack)
{
    TStack<int> A(3);

    ASSERT_NO_THROW(TStack<int> s(A));
}

TEST(TStack, can_push_and_get)
{
    TStack<int> A(3);
    A.Push(3);

    ASSERT_EQ(3, A.Get());
}

TEST(TStack, is_full_false)
{
    TStack<int> A(3);
    ASSERT_FALSE(A.IsFull());
}

TEST(TStack, is_full_true)
{
    TStack <int> S(3);
    S.Push(1);
    S.Push(2);
    S.Push(3);
    ASSERT_TRUE(S.IsFull());
}

TEST(TStack, is_empty_false)
{
    TStack <int> A(3);
    A.Push(3);
    A.Push(4);
    ASSERT_FALSE(A.IsEmpty());
}

TEST(TStack, is_empty_true)
{
    TStack<int> A(3);
    ASSERT_TRUE(A.IsEmpty());
}

TEST(TStack, throws_when_put_elem_in_full_stack)
{
    TStack <int> S(3);
    S.Push(3);
    S.Push(4);
    S.Push(5);
    ASSERT_ANY_THROW(S.Push(6));
}

TEST(TStack, throws_when_get_elem_from_empty_stack)
{
    TStack<int> A(3);
    ASSERT_ANY_THROW(A.Get());
}

TEST(TStack, can_get_min_elem)
{
    TStack <int> A(3);
    A.Push(5);
    A.Push(4);
    A.Push(3);
    ASSERT_EQ(3, A.MinElem());
}

TEST(TStack, can_get_max_elem)
{
    TStack <int> A(3);
    A.Push(5);
    A.Push(4);
    A.Push(3);
    ASSERT_EQ(5, A.MaxElem());
}