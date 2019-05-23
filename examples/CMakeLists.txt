add_executable(
  ${PROJECT_NAME}_ex1
  ${CMAKE_CURRENT_LIST_DIR}/Ex1.cpp
  )

target_link_libraries(
  ${PROJECT_NAME}_ex1
  graphics_renderer
  )
