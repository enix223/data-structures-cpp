add_executable(
    lrvalues_test
    lrvalues_test.cpp
)

target_link_libraries(
    lrvalues_test
    GTest::gtest_main
)

gtest_discover_tests(lrvalues_test)
