cc_library(
    name = "double_linked_queue",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["inc/*.hpp"]),
    includes = ["inc"],
    visibility = [
        "//lib:__subpackages__",
        "//src:__subpackages__",
        "//test:__subpackages__",
    ],
    deps = [
        "//lib/double_linked_list",
        "//lib/queue",
    ],
)
