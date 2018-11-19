file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/arrays_strings/*.cpp
        ${PROJECT_SOURCE_DIR}/src/bit_manipulation/*.cpp
        ${PROJECT_SOURCE_DIR}/src/linked_lists/*.cpp
        ${PROJECT_SOURCE_DIR}/src/recursion_dp/*.cpp
        ${PROJECT_SOURCE_DIR}/src/sorting_searching/*.cpp
        ${PROJECT_SOURCE_DIR}/src/stacks_queues/*.cpp
        ${PROJECT_SOURCE_DIR}/src/trees_graphs/*.cpp
        )

add_library(ctci STATIC ${SOURCE_FILES})