add_executable(
    heap_test
    heap_test.cpp
)

target_include_directories(
    heap_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/common/inc/
    ${CMAKE_SOURCE_DIR}/lib/heap/inc/
)

target_link_libraries(
    heap_test
    GTest::gtest_main
)

gtest_discover_tests(heap_test)
