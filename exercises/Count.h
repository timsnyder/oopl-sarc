// -------
// Count.h
// -------

#ifndef Count_h
#define Count_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // iterator, random_access_iterator_tag

template <typename II, typename T>
std::ptrdiff_t my_count_1 (II b, II e, const T& v) {
    std::ptrdiff_t c = 0;
    while (b != e) {
        if (*b == v)
            ++c;
        ++b;}
    return c;}

/*
namespace std {

template <typename C, typename T, typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
struct iterator {
    using iterator_category = C;
    using value_type        = T;
    using difference_type   = D;
    using pointer           = P;
    using reference         = R;}

} // std
*/

template <typename I>
struct my_iterator_traits : std::iterator<typename I::iterator_category, typename I::value_type, typename I::difference_type, typename I::pointer, typename I::reference> {
/*
    using iterator_category = typename I::iterator_category;
    using        value_type = typename I::value_type;
    using   difference_type = typename I::difference_type;
    using           pointer = typename I::pointer;
    using         reference = typename I::reference;
*/
};

template <typename T>
struct my_iterator_traits<T*> : std::iterator<std::random_access_iterator_tag, T> {
/*
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;
    using reference         = value_type&;
*/
};

template <typename T>
struct my_iterator_traits<const T*> : std::iterator<std::random_access_iterator_tag, const T> {
/*
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = const T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;
    using reference         = value_type&;
*/
};

template <typename II, typename T>
typename my_iterator_traits<II>::difference_type my_count_2 (II b, II e, const T& v) {
    typename my_iterator_traits<II>::difference_type c = 0;
    while (b != e) {
        if (*b == v)
            ++c;
        ++b;}
    return c;}

#endif // Count_h
