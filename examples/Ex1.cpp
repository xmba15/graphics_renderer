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

int main(int argc, char *argv[])
{
    const int width = 400;
    const int height = 400;

    Image m(width, height);

    m.render();
    std::cout << "Check the rendered output image: out.ppm" << "\n";

    return 0;
}
