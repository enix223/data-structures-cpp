cc_test(
    name = "heap_test",
    timeout = "short",
    srcs = glob(["**/*.cpp"]),
    copts = ["-std=c++20"],
    deps = [
        "//lib/heap",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
