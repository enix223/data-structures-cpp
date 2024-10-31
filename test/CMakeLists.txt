include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG        v1.15.x
    SOURCE_DIR     deps/googletest
)
FetchContent_MakeAvailable(googletest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(GoogleTest)

add_subdirectory(heap)
add_subdirectory(assign)
add_subdirectory(lrvalues)
add_subdirectory(binary_search)
add_subdirectory(dynamic_array)
add_subdirectory(linked_list)
