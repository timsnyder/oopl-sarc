// ---------
// Reverse.h
// ---------

#ifndef Reverse_h
#define Reverse_h

#include <iterator> // bidirectional_iterator_tag, iterator_traits random_access_iterator_tag

/*
namespace std {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

} // std
*/

template <typename BI>
void my_reverse_aux (BI b, BI e, std::bidirectional_iterator_tag) {
    while ((b != e) && (b != --e)) {
        std::swap(*b, *e);
        ++b;}}

template <typename RI>
void my_reverse_aux (RI b, RI e, std::random_access_iterator_tag) {
    while (b < --e) {
        std::swap(*b, *e);
        ++b;}}

template <typename I>
void my_reverse (I b, I e) {
    my_reverse_aux(b, e, typename std::iterator_traits<I>::iterator_category());}

#endif // Reverse_h
