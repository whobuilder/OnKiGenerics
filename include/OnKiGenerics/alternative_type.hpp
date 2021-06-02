#ifndef ONKIGENERICS_ALTERNATIVE_TYPE_H
#define ONKIGENERICS_ALTERNATIVE_TYPE_H
#include <type_traits>

namespace onkigenerics {

template<typename Default, typename Alternative = void>
using AlternativeType = std::conditional_t<std::is_same_v<Alternative, void>, Default, Alternative>;

}

#endif /* ONKIGENERICS_ALTERNATIVE_TYPE_H */
