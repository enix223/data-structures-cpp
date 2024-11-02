cc_library(
    name = "single_linked_queue",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["inc/*.hpp"]),
    includes = ["inc"],
    visibility = [
        "//lib:__subpackages__",
        "//src:__subpackages__",
        "//test:__subpackages__",
    ],
    deps = [
        "//lib/queue",
    ],
)
