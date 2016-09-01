// -------------
// SharedPtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // make_shared, shared_ptr

using namespace std;

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

int main () {
    cout << "SharedPtr.c++" << endl;

    assert(A::c == 0);

    {
//  shared_ptr<A> x = new A; // error: no viable conversion from 'A *' to 'shared_ptr<A>'
    shared_ptr<A> x(new A);
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    shared_ptr<A> x = make_shared<A>();
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    auto x = make_shared<A>();
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    shared_ptr<A> x(new A);
    shared_ptr<A> y = x;
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    shared_ptr<A> x(new A);
    shared_ptr<A> y(new A);
    assert(A::c == 2);
    x = y;
    assert(A::c == 1);
    }

    assert(A::c == 0);

    cout << "Done." << endl;
    return 0;}
