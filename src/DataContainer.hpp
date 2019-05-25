/**
 * @file    DataContainer.hpp
 *
 * @brief   Construction of DataContainer
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

#ifndef DATACONTAINER_HPP_
#define DATACONTAINER_HPP_

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ostream>
#include <utility>

namespace graphics
{
template <typename T, size_t DIM = 3> class DataContainer
{
 public:
    using iterator = T *;
    using const_iterator = T *;

    DataContainer();
    explicit DataContainer(T *data);

    virtual ~DataContainer();

    T &operator[](size_t i);
    const T &operator[](size_t i) const;

    virtual DataContainer &operator=(const DataContainer &other);
    virtual bool operator==(const DataContainer &other);

    virtual DataContainer &operator+(const DataContainer &other);
    virtual DataContainer &operator-(const DataContainer &other);

    virtual DataContainer &operator*(T scalar);
    virtual DataContainer &operator/(T scalar);

    virtual T dot(const DataContainer &other);

    double l2norm() const;
    void l2normalize();

    iterator begin()
    {
        return this->_data;
    }

    iterator end()
    {
        return (this->_data + DIM);
    }

    const_iterator begin() const
    {
        return this->_data;
    }

    const_iterator end() const
    {
        return this->_data + DIM;
    }

    size_t size() const
    {
        return DIM;
    }

    friend std::ostream &operator<<(std::ostream &os, const DataContainer &dc)
    {
        for (auto it = dc.begin(); it != dc.end(); ++it) {
            os << *it << "\n";
        }
        return os;
    }

 protected:
    T *_data;
};

template <typename T, size_t DIM> DataContainer<T, DIM>::DataContainer()
{
    this->_data = new T[DIM];

    for (size_t i = 0; i < DIM; ++i) {
        this->_data[i] = T();
    }
}

template <typename T, size_t DIM> DataContainer<T, DIM>::DataContainer(T *data)
{
    assert(data != nullptr);
    this->_data = new T[DIM];

    for (size_t i = 0; i < DIM; ++i) {
        _data[i] = data[i];
    }
}

template <typename T, size_t DIM> DataContainer<T, DIM>::~DataContainer()
{
    delete[] _data;
}

template <typename T, size_t DIM> T &DataContainer<T, DIM>::operator[](size_t i)
{
    assert(i < DIM);
    return this->_data[i];
}

template <typename T, size_t DIM>
const T &DataContainer<T, DIM>::operator[](size_t i) const
{
    assert(i < DIM);
    return this->_data[i];
}

template <typename T, size_t DIM>
DataContainer<T, DIM> &DataContainer<T, DIM>::
operator=(const DataContainer &other)
{
    if (this != &other) {
        this->_data = new T[DIM];
        for (size_t i = 0; i < DIM; ++i) {
            this->_data[i] = other._data[i];
        }
    }

    return *this;
}

template <typename T, size_t DIM>
bool DataContainer<T, DIM>::operator==(const DataContainer &other)
{
    for (size_t i = 0; i < DIM; ++i) {
        if (this->_data[i] != other._data[i]) {
            return false;
        }
    }
    return true;
}

template <typename T, size_t DIM>
DataContainer<T, DIM> &DataContainer<T, DIM>::
operator+(const DataContainer &other)
{
    for (size_t i = 0; i < DIM; ++i) {
        this->_data[i] += other._data[i];
    }
    return *this;
}

template <typename T, size_t DIM>
DataContainer<T, DIM> &DataContainer<T, DIM>::
operator-(const DataContainer &other)
{
    for (size_t i = 0; i < DIM; ++i) {
        this->_data[i] -= other._data[i];
    }
    return *this;
}

template <typename T, size_t DIM>
DataContainer<T, DIM> &DataContainer<T, DIM>::operator*(T scalar)
{
    for (size_t i = 0; i < DIM; ++i) {
        this->_data[i] *= scalar;
    }
    return *this;
}

template <typename T, size_t DIM>
DataContainer<T, DIM> &DataContainer<T, DIM>::operator/(T scalar)
{
    assert(scalar != T());

    for (size_t i = 0; i < DIM; ++i) {
        this->_data[i] /= scalar;
    }
    return *this;
}

template <typename T, size_t DIM>
T DataContainer<T, DIM>::dot(const DataContainer &other)
{
    T accum = T();
    for (size_t i = 0; i < DIM; ++i) {
        accum += this->_data[i] * other._data[i];
    }

    return accum;
}

template <typename T, size_t DIM> double DataContainer<T, DIM>::l2norm() const
{
    double accum = 0;
    for (size_t i = 0; i < DIM; ++i) {
        accum += this->_data[i];
    }

    return std::sqrt(accum);
}

template <typename T, size_t DIM> void DataContainer<T, DIM>::l2normalize()
{
    if (this->l2norm() == 0) {
        return;
    }

    *this = *this / this->l2norm();
}

}  // namespace graphics

#endif /* DATACONTAINER_HPP_ */
