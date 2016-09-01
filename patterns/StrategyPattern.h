// -----------------
// StrategyPattern.h
// -----------------

#ifndef StrategyPattern_h
#define StrategyPattern_h

#include <string> // string

using namespace std;

struct DuckInterface {
    virtual ~DuckInterface () {}

    virtual string fly   () = 0;
    virtual string quack () = 0;
    virtual string swim  () = 0;};

struct DecoyDuck : DuckInterface {
    string fly () {
        return "";}

    string quack () {
        return "decoy ducks can quack";}

    string swim () final {
        return "decoy ducks can swim";}};

struct MallardDuck : DuckInterface {
    string fly () {
        return "mallard ducks can fly";}

    string quack () {
        return "mallard ducks can quack";}

    string swim () final {
        return "mallard ducks can swim";}};

struct ModelDuck : DuckInterface {
    string fly () {
        return "";}

    string quack () {
        return "";}

    string swim () final {
        return "model ducks can swim";}};

struct RubberDuck : DuckInterface {
    string fly () {
        return "";}

    string quack () {
        return "rubber ducks can quack";}

    string swim () final {
        return "rubber ducks can swim";}};

#endif // StrategyPattern_h
