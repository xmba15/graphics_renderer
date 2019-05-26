/**
 * @file    Ex1.cpp
 *
 * @brief   test image renderer
 *
 * @author  btran
 *
 * @date    2019-05-24
 *
 * Copyright (c) organization
 *
 */

#include "DataContainer.hpp"
#include "Mat.hpp"
#include "Utility.hpp"
#include "Vector.hpp"

#include <iostream>
using Image = graphics::Image<double>;
using Vec4d = graphics::DataContainer<double, 4>;

int main(int argc, char *argv[])
{
    const int width = 400;
    const int height = 400;

    Image m(width, height);

    // std::cout << m.width() << "\n";
    // std::cout << m.dim() << "\n";
    m.render();

    double data1[] = {1, 2, 3, 4};
    double data2[] = {-1, -2, 3, 4};
    double dataSum[] = {0, 0, 6, 8};

    Vec4d v1(data1), v2(data2), vSum(dataSum);

    std::cout << v1 << "\n";
    std::cout << "-------"
              << "\n";
    std::cout << v2 << "\n";
    std::cout << "-------"
              << "\n";
    std::cout << vSum << "\n";
    std::cout << "-------"
              << "\n";

    // std::cout << v1 + v2 << "\n";
    Vec4d lol;
    lol = v1 + v2;

    // Vec4d other(dataSum);
    // Vec4d other = v1 + v2;
    // std::cout << other << "\n";
    // std::cout << v1 << "\n";

    v1 /= 2;

    std::cout << v1 << "\n";

    // bool temp = (vSum == (v1 + v2));
    // bool temp = (vSum == other);
    // temp = true;

    // std::cout << temp << "\n";

    return 0;
}
