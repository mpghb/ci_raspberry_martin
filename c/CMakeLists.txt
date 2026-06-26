cmake_minimum_required(VERSION 3.16)
project(ci_raspberry_c C)

set(CMAKE_C_STANDARD 11)

# --- Produktions-Library ---
add_library(math_utils src/math_utils.c)
target_include_directories(math_utils PUBLIC include)

# --- Unity via FetchContent (wird automatisch von GitHub heruntergeladen) ---
include(FetchContent)
FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG        v2.6.0
)
FetchContent_MakeAvailable(unity)

# --- Test-Binary ---
add_executable(test_math_utils tests/test_math_utils.c)
target_link_libraries(test_math_utils PRIVATE math_utils unity)
target_include_directories(test_math_utils PRIVATE include)

# --- CTest Integration ---
enable_testing()
add_test(NAME math_utils_tests COMMAND test_math_utils)
