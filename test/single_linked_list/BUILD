cc_test(
    name = "single_linked_list_test",
    timeout = "short",
    srcs = glob(["**/*.cpp"]),
    copts = select({
        "@platforms//os:linux": ["-std=c++20"],
        "@platforms//os:windows": ["/std:c++20"],
        "@platforms//os:macos": ["-std=c++20"],
    }),
    deps = [
        "//lib/single_linked_list",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
