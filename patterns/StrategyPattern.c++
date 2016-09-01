// -------------------
// StrategyPattern.c++
// -------------------

// http://en.wikipedia.org/wiki/Strategy_pattern
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <memory> // make_shared, shared_ptr
#include <string> // ==

#include "gtest/gtest.h"

#include "StrategyPattern.h"

using namespace std;

TEST(Strategy_Pattern_Fixture, test_1) {
    DecoyDuck x;
    ASSERT_EQ("",                      x.fly());
    ASSERT_EQ("decoy ducks can quack", x.quack());
    ASSERT_EQ("decoy ducks can swim",  x.swim());}

TEST(Strategy_Pattern_Fixture, test_2) {
    MallardDuck x;
    ASSERT_EQ("mallard ducks can fly",   x.fly());
    ASSERT_EQ("mallard ducks can quack", x.quack());
    ASSERT_EQ("mallard ducks can swim",  x.swim());}

TEST(Strategy_Pattern_Fixture, test_3) {
    ModelDuck x;
    ASSERT_EQ("",                     x.fly());
    ASSERT_EQ("",                     x.quack());
    ASSERT_EQ("model ducks can swim", x.swim());}

TEST(Strategy_Pattern_Fixture, test_4) {
    RubberDuck x;
    ASSERT_EQ("",                       x.fly());
    ASSERT_EQ("rubber ducks can quack", x.quack());
    ASSERT_EQ("rubber ducks can swim",  x.swim());}
