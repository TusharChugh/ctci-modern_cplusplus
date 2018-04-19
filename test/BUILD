TEST_COPTS = [
    "-pedantic",
    "-pedantic-errors",
    "-std=c++11",
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
        "@benchmark//:benchmark",
        "@benchmark//:benchmark_internal_headers",        
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        "//include/arrays_strings:arrays_strings",
        "//include/linked_lists:linked_lists",
        "//include/backtracking:backtracking",
        "//include/bit_manipulation:bit_manipulation",
        "//include/math_logic:math_logic",
        "//include/recursion_dp:recursion_dp",
        "//include/stacks_queues:stacks_queues",
        "//include/trees_graphs:trees_graphs",
    ],
) 

cc_test(
name = "algorithms-benchmark",
size = "small",
srcs = glob(["benchmark/*.cpp"]),
copts = TEST_COPTS,

    deps = [
        "@benchmark//:benchmark",
        "@benchmark//:benchmark_internal_headers",        
        "@gtest//:gtest",
        "//include/arrays_strings:arrays_strings",
        "//include/linked_lists:linked_lists",
        "//include/backtracking:backtracking",
        "//include/bit_manipulation:bit_manipulation",
        "//include/math_logic:math_logic",
        "//include/recursion_dp:recursion_dp",
        "//include/stacks_queues:stacks_queues",
        "//include/trees_graphs:trees_graphs",
    ],
) 

#[
#    cc_test(
#    name = test_src[:-len(".cpp")],
#    size = "small",
#    srcs = [test_src],
#    args = TEST_ARGS + PER_SRC_TEST_ARGS.get(test_src, []),
#   copts = TEST_COPTS,
    
#        deps = [
#            "@benchmark//:benchmark",
#            "@benchmark//:benchmark_internal_headers",        
#            "@gtest//:gtest",
#            "//include/arrays_strings:arrays_strings",
#            "//include/backtracking:backtracking",
#            "//include/bit_manipulation:bit_manipulation",
#            "//include/math_logic:math_logic",
#            "//include/recursion_dp:recursion_dp",
#            "//include/stacks_queues:stacks_queues",
#            "//include/trees_graphs:trees_graphs",
#        ] + (
#            [ "@gtest//:gtest_main"] if (test_src[-len("test.cpp"):] == "test.cpp") else []
#        ),
#    ) for test_src in glob(["*.cc", "*.cpp"])
#]

