// ------------
// Distance.c++
// ------------

// http://www.cplusplus.com/reference/algorithm/distance/

#include <algorithm>  // equal, distance
#include <functional> // function

#include "gtest/gtest.h"

#include "Distance.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Distance_Array_Signature = function<ptrdiff_t (const int*, const int*)>;

struct Distance_Array_Fixture : TestWithParam<Distance_Array_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Distance_Array_Instantiation,
    Distance_Array_Fixture,
    Values(
           distance<const int*>,
        my_distance<const int*>));

TEST_P(Distance_Array_Fixture, test_0) {
    const int a[] = {2, 3, 4};
    ASSERT_EQ(0, GetParam()(a, a));}

TEST_P(Distance_Array_Fixture, test_1) {
    const int a[] = {2, 3, 4};
    ASSERT_EQ(1, GetParam()(a, a + 1));}

TEST_P(Distance_Array_Fixture, test_2) {
    const int a[] = {2, 3, 4};
    ASSERT_EQ(2, GetParam()(a, a + 2));}

TEST_P(Distance_Array_Fixture, test_3) {
    const int a[] = {2, 3, 4};
    ASSERT_EQ(3, GetParam()(a, a + 3));}
