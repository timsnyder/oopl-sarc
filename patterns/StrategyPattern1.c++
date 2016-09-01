// --------------------
// StrategyPattern1.c++
// --------------------

// http://en.wikipedia.org/wiki/Strategy_pattern
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <memory> // make_shared, shared_ptr
#include <string> // ==

#include "gtest/gtest.h"

#include "StrategyPattern1.h"

using namespace std;

TEST(Strategy_Pattern_Fixture, test_1) {
    DuckInterface* p = new DecoyDuck;
    ASSERT_EQ("can not fly", p->fly());
    ASSERT_EQ("can quack",   p->quack());
    ASSERT_EQ("can swim",    p->swim());
    delete p;}

TEST(Strategy_Pattern_Fixture, test_2) {
    shared_ptr<DuckInterface> p = shared_ptr<DuckInterface>(new MallardDuck);
    ASSERT_EQ("can fly",   p->fly());
    ASSERT_EQ("can quack", p->quack());
    ASSERT_EQ("can swim",  p->swim());}

TEST(Strategy_Pattern_Fixture, test_3) {
    shared_ptr<ModelDuck> p = make_shared<ModelDuck>();
    ASSERT_EQ("can not fly",   p->fly());
    ASSERT_EQ("can not quack", p->quack());
    ASSERT_EQ("can swim",      p->swim());}

TEST(Strategy_Pattern_Fixture, test_4) {
    auto p = make_shared<RubberDuck>();
    ASSERT_EQ("can not fly", p->fly());
    ASSERT_EQ("can quack",   p->quack());
    ASSERT_EQ("can swim",    p->swim());}
