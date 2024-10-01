add_executable(
    dynamic_array_test
    dynamic_array_test.cpp
)

target_include_directories(
    dynamic_array_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/common/inc/
    ${CMAKE_SOURCE_DIR}/lib/dynamic_array/inc/
)

target_link_libraries(
    dynamic_array_test
    GTest::gtest_main
)

gtest_discover_tests(dynamic_array_test)
