cc_library(
    name = "common",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["inc/*.hpp"]),
    copts = ["-std=c++20"],
    includes = ["inc"],
    visibility = [
        "//lib:__subpackages__",
        "//src:__subpackages__",
        "//test:__subpackages__",
    ],
)
