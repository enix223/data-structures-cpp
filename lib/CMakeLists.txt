set(HEADERS
    common/inc/comparable.hpp
    heap/inc/heap.hpp
    linked_list/inc/linked_list.hpp
    binary_search/inc/binary_search.hpp
    dynamic_array/inc/dynamic_array.hpp
    linked_list/inc/linked_list.hpp
)

add_library(cppds INTERFACE ${HEADERS})
