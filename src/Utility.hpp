/**
 * @file    Utility.hpp
 *
 * @brief   Utility Functions
 *
 * @author  btran
 *
 * @date    2019-05-23
 *
 * framework
 *
 * Copyright (c) organization
 *
 */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <ostream>

namespace utility
{
template <typename T,
          template <typename, typename = std::allocator<T>> class Container>
std::ostream &operator<<(std::ostream &os, const Container<T> &container)
{
    using ContainerType = Container<T>;
    for (typename ContainerType::const_iterator it = container.begin();
         it != container.end(); ++it) {
        os << *it << " ";
    }

    return os;
}
}  // namespace utility

#endif /* UTILITY_HPP_ */
