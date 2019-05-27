add_executable(
  unit_tests
  TestDataContainer.cpp
  TestVector.cpp
  )

target_link_libraries(
  unit_tests
  PUBLIC
  graphics_renderer
  PRIVATE
  gtest_main
)

add_test(
  NAME
  unit_tests
  COMMAND
  $<TARGET_FILE:unit_tests>
  )
