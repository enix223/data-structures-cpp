cc_test(
    name = "stack_test",
    timeout = "short",
    srcs = glob(["**/*.cpp"]),
    copts = select({
        "@platforms//os:linux": ["-std=c++20"],
        "@platforms//os:windows": ["/std:c++20"],
        "@platforms//os:macos": ["-std=c++20"],
    }),
    deps = [
        "//lib/linked_list_stack",
        "//lib/stack",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
