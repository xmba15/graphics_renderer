/**
 * @file    Mat.hpp
 *
 * @brief   Construction of Matrix Container
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

#ifndef MAT_HPP_
#define MAT_HPP_

#include "Vector.hpp"
#include <algorithm>
#include <fstream>
#include <string>

namespace graphics
{
template <typename T, size_t DIM = 3> class Matrix
{
 public:
    using VectorType = Vector<T, DIM>;
    using Ptr = std::shared_ptr<Matrix>;

    Matrix(size_t width, size_t height);

    ~Matrix()
    {
        delete[] _data;
    }

    const size_t &width() const
    {
        return this->_width;
    }

    const size_t &height() const
    {
        return this->_height;
    }

    const size_t &dim() const
    {
        return this->_dim;
    }

 protected:
    size_t _width;
    size_t _height;
    size_t _dim = DIM;
    VectorType *_data;
};

template <typename T, size_t DIM>
Matrix<T, DIM>::Matrix(size_t width, size_t height)
{
    assert(width != 0 && height != 0);
    this->_width = width;
    this->_height = height;
    this->_data = new VectorType[width * height];

    for (size_t j = 0; j < height; ++j) {
        for (size_t i = 0; i < width; ++i) {
            T curPixel[DIM] = {j / static_cast<T>(height),
                               i / static_cast<T>(width), 0};
            this->_data[i + j * _width] = VectorType(curPixel);
        }
    }
}

template <typename T> class Image : public Matrix<T>
{
 public:
    using Ptr = std::shared_ptr<Image>;
    using Matrix<T>::Matrix;

    void render(const std::string &output = "out.ppm");
};

template <typename T> void Image<T>::render(const std::string &output)
{
    std::ofstream ofs;
    ofs.open(output);
    ofs << "P6\n" << this->width() << " " << this->height() << "\n255\n";
    for (size_t i = 0; i < this->height() * this->width(); ++i) {
        for (size_t j = 0; j < 3; j++) {
            ofs << static_cast<char>(
                255 * std::max(0.0, std::min(1.0, this->_data[i][j])));
        }
    }
    ofs.close();
}

}  // namespace graphics

#endif /* MAT_HPP_ */
