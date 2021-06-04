#ifndef ONKIGENERICS_REMOVE_CVREF_H
#define ONKIGENERICS_REMOVE_CVREF_H
#include <type_traits>
namespace onkigenerics {
template<class T>
struct remove_cvref
{
    typedef std::remove_cv_t<std::remove_reference_t<T>> type;
};

template<class T>
using remove_cvref_t = typename remove_cvref<T>::type;
}// namespace onkigenerics

#endif /* ONKIGENERICS_REMOVE_CVREF_H */
