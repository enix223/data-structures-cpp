add_executable(
    queue_test
    queue_int_test.cpp
)

target_include_directories(
    queue_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/common/inc/
    ${CMAKE_SOURCE_DIR}/lib/queue/inc/
    ${CMAKE_SOURCE_DIR}/lib/single_linked_queue/inc/
    ${CMAKE_SOURCE_DIR}/lib/single_linked_list/inc/
    ${CMAKE_SOURCE_DIR}/lib/double_linked_list/inc/
)

target_link_libraries(
    queue_test
    GTest::gtest_main
)

gtest_discover_tests(queue_test)
