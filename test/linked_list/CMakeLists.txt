add_executable(
    linked_list_test
    linked_list_test.cpp
)

target_include_directories(
    linked_list_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/common/inc/
    ${CMAKE_SOURCE_DIR}/lib/linked_list/inc/
)

target_link_libraries(
    linked_list_test
    GTest::gtest_main
)

gtest_discover_tests(linked_list_test)
