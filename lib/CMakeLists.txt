set(HEADERS
    common/inc/comparable.hpp
    heap/inc/heap.hpp
    binary_search/inc/binary_search.hpp
    dynamic_array/inc/dynamic_array.hpp
    single_linked_list/inc/single_linked_list.hpp
    double_linked_list/inc/double_linked_list.hpp
    queue/inc/queue.hpp
    single_linked_queue/inc/single_linked_queue.hpp
)

add_library(cppds INTERFACE ${HEADERS})
