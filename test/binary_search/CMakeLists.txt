add_executable(
    binary_search_test
    binary_search_test.cpp
)

target_include_directories(
    binary_search_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/common/inc/
    ${CMAKE_SOURCE_DIR}/lib/binary_search/inc/
)

target_link_libraries(
    binary_search_test
    GTest::gtest_main
)

gtest_discover_tests(binary_search_test)
