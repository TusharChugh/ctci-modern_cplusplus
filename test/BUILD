TEST_COPTS = [
    "-pedantic",
    "-pedantic-errors",
    "-std=c++17",
    "-Wall",
    "-Wextra",
    "-Wshadow",
    "-Wfloat-equal",
    "-fstrict-aliasing",
]

TEST_ARGS = ["--benchmark_min_time=0.01"]

PER_SRC_TEST_ARGS = ({
    "user_counters_tabular_test.cc": ["--benchmark_counters_tabular=true"],
})

cc_test(
    name = "algorithms-test",
    size = "small",
    srcs = glob(["tests/**/*.cpp"]),
    copts = TEST_COPTS,
    deps = [
        "//include/arrays_strings:arrays_strings",
        "//include/bit_manipulation",
        "//include/linked_lists",
        "//include/math_logic",
        "//include/recursion_dp",
        "//include/sorting_searching",
        "//include/stacks_queues",
        "//include/trees_graphs",
        "@benchmark//:benchmark",
        "@benchmark//:benchmark_internal_headers",
        "@gtest//:gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "algorithms-benchmark",
    size = "small",
    srcs = glob(["benchmark/*.cpp"]),
    copts = TEST_COPTS,
    deps = [
        "//include/arrays_strings",
        "//include/linked_lists",
        "//include/math_logic",
        "//include/recursion_dp",
        "//include/sorting_searching",
        "//include/stacks_queues",
        "//include/trees_graphs",
        "@benchmark//:benchmark",
        "@benchmark//:benchmark_internal_headers",
        "@gtest//:gtest",
    ],
)
