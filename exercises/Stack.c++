// ---------
// Stack.c++
// ---------

// http://en.cppreference.com/w/cpp/container/stack

#include <cassert> // assert
#include <list>    // list
#include <stack>   // stack
#include <vector>  // vector

#include "gtest/gtest.h"

#include "Stack.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Stack_Fixture : Test {
    using stack_type = T;};

using
    stack_types =
    Types<
           stack<int>,
           stack<int, list<int>>,
           stack<int, vector<int>>,
        my_stack<int>,
        my_stack<int, list<int>>,
        my_stack<int, vector<int>>>;

TYPED_TEST_CASE(Stack_Fixture, stack_types);

TYPED_TEST(Stack_Fixture, test_1) {
    using stack_type = typename TestFixture::stack_type;

    stack_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(), 0);

    x.push(2);
    x.push(3);
    x.push(4);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(4, x.top());

    x.pop();
    ASSERT_EQ(2, x.size());
    ASSERT_EQ(3, x.top());

    x.top() = 4;
    ASSERT_EQ(4, x.top());}

TYPED_TEST(Stack_Fixture, test_2) {
    using stack_type = typename TestFixture::stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    x.top() = 5;
    ASSERT_EQ(5, x.top());

    const stack_type& r = x;
//  r.top() = 6;             // error: member function 'push' not viable: 'this' argument has type 'const stack_type'
    ASSERT_EQ(5, r.top());}

TYPED_TEST(Stack_Fixture, test_3) {
    using stack_type = typename TestFixture::stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    stack_type y = x;
    ASSERT_EQ(x, y);

    y.pop();
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(4, x.top());
    ASSERT_EQ(2, y.size());
    ASSERT_EQ(3, y.top());}

TYPED_TEST(Stack_Fixture, test_4) {
    using stack_type = typename TestFixture::stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    stack_type y;
    y.push(5);
    y.push(6);

    y = x;
    ASSERT_EQ(x, y);

    y.pop();
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(4, x.top());
    ASSERT_EQ(2, y.size());
    ASSERT_EQ(3, y.top());}

TYPED_TEST(Stack_Fixture, test_5) {
    using stack_type = typename TestFixture::stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    stack_type y;
    y.push(2);
    y.push(3);
    y.push(4);

    ASSERT_FALSE(x != y);
    ASSERT_FALSE(x <  y);
    ASSERT_FALSE(x >  y);
    ASSERT_TRUE (x <= y);
    ASSERT_TRUE (x >= y);}
