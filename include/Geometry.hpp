/**
 * @file    Geometry.hpp
 *
 * @brief   Construction of Necessary Classes for Graphics
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

#ifndef GEOMETRY_HPP_
#define GEOMETRY_HPP_

#include "DataContainer.hpp"
#include <memory>

namespace graphics
{
template <typename T, size_t DIM = 3>
class Vector : public DataContainer<T, DIM>
{
 public:
    using Ptr = std::shared_ptr<Vector>;

    Vector() : DataContainer<T, DIM>()
    {
    }

    explicit Vector(T *data) : DataContainer<T, DIM>(data)
    {
    }

    Vector &operator+(const Vector &other)
    {
        this->DataContainer<T, DIM>::operator+(other);
        return *this;
    }

    Vector &operator-(const Vector &other)
    {
        this->DataContainer<T, DIM>::operator-(other);
        return *this;
    }

    Vector &operator*(T scalar)
    {
        this->DataContainer<T, DIM>::operator*(scalar);
        return *this;
    }

    Vector &operator/(T scalar)
    {
        this->DataContainer<T, DIM>::operator/(scalar);
        return *this;
    }

    const T &x() const
    {
        return this->_data[0];
    }

    const T &y() const
    {
        return this->_data[1];
    }

    const T &z() const
    {
        return this->_data[2];
    }

    T &x()
    {
        return this->_data[0];
    }

    T &y()
    {
        return this->_data[1];
    }

    T &z()
    {
        return this->_data[2];
    }
};

}  // namespace graphics

#endif /* GEOMETRY_HPP_ */
