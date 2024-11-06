add_executable(
    stack_test
    stack_int_test.cpp
)

target_include_directories(
    stack_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/stack/inc/
    ${CMAKE_SOURCE_DIR}/lib/linked_list_stack/inc/
    ${CMAKE_SOURCE_DIR}/lib/array_stack/inc/
)

target_link_libraries(
    stack_test
    GTest::gtest_main
)

gtest_discover_tests(stack_test)
