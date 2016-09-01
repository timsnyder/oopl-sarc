// ------------------
// StrategyPattern1.h
// ------------------

#ifndef StrategyPattern1_h
#define StrategyPattern1_h

#include <string> // string

using namespace std;

struct DuckInterface {
    virtual ~DuckInterface () {}

    virtual string fly   () = 0;
    virtual string quack () = 0;
    virtual string swim  () = 0;};

struct AbstractDuck : DuckInterface {
    string swim () final {
        return "can swim";}};



struct DecoyDuck : AbstractDuck {
    string fly () {
        return "can not fly";}

    string quack () {
        return "can quack";}};

struct MallardDuck : AbstractDuck {
    string fly () {
        return "can fly";}

    string quack () {
        return "can quack";}};

struct ModelDuck : AbstractDuck {
    string fly () {
        return "can not fly";}

    string quack () {
        return "can not quack";}};

struct RubberDuck : AbstractDuck {
    string fly () {
        return "can not fly";}

    string quack () {
        return "can quack";}};

#endif // StrategyPattern1_h
