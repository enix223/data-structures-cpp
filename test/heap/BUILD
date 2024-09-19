cc_test(
    name = "heap_test",
    timeout = "short",
    srcs = glob(["**/*.cpp"]),
    copts = select({
        "@platforms//os:linux": ["-std=c++20"],
        "@platforms//os:windows": ["/std:c++20"],
        "@platforms//os:macos": ["-std=c++20"],
    }),
    deps = [
        "//lib/heap",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
