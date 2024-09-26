add_executable(
    assign_test
    assign_test.cpp
)

target_link_libraries(
    assign_test
    GTest::gtest_main
)

gtest_discover_tests(assign_test)
