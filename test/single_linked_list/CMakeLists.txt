add_executable(
    single_linked_list_test
    single_linked_list_int_test.cpp
    single_linked_list_class_test.cpp
)

target_include_directories(
    single_linked_list_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/common/inc/
    ${CMAKE_SOURCE_DIR}/lib/single_linked_list/inc/
)

target_link_libraries(
    single_linked_list_test
    GTest::gtest_main
)

gtest_discover_tests(single_linked_list_test)
