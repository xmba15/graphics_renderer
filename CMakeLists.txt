cmake_minimum_required(VERSION 3.0)

project(gr)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE DEBUG)

add_subdirectory(src)
add_subdirectory(examples)

include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )

enable_testing()
add_subdirectory(test)
