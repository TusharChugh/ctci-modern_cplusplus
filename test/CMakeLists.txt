include(${PROJECT_SOURCE_DIR}/cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()


file(GLOB TEST_FILES
        ${PROJECT_SOURCE_DIR}/test/tests/arrays_strings/*.cpp
        ${PROJECT_SOURCE_DIR}/test/tests/bit_manipulation/*.cpp
        ${PROJECT_SOURCE_DIR}/test/tests/linked_lists/*.cpp
        ${PROJECT_SOURCE_DIR}/test/tests/recursion_dp/*.cpp
        ${PROJECT_SOURCE_DIR}/test/tests/sorting_searching/*.cpp
        ${PROJECT_SOURCE_DIR}/test/tests/stacks_queues/*.cpp
        ${PROJECT_SOURCE_DIR}/test/tests/trees_graphs/*.cpp
    )


add_executable(unittest_ctci tests/unit_tests.cpp ${TEST_FILES})
target_link_libraries(unittest_ctci gtest_main ctci pthread)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unittest_container
)
