cmake_minimum_required(VERSION 3.0)

project(project_name)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE)
add_definitions("-Wall")

# find_package()
# include_directories()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB BASIC_SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
  )

add_executable(${PROJECT_NAME}_ex1
  ${CMAKE_CURRENT_SOURCE_DIR}/examples/Ex1.cpp
  ${BASIC_SOURCE_FILES}
  )

# target_link_libraries(${PROJECT_NAME})
