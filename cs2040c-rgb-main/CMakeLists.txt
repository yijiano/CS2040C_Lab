cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project("CS2040C Lab 2 RGB Example")

add_library(rgb RGB.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/8a6feabf04bec8fb125e0df0ad1195c42350725f.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(rgb_test RGB_test.cpp)
target_link_libraries(rgb_test gtest_main rgb)
add_test(NAME RGBTest COMMAND rgb_test)
