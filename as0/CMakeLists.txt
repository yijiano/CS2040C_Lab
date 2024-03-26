cmake_minimum_required(VERSION 3.0.0)
project("CS2040C AY23/24 SEM2 ASSIGNMENT 0")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(RGB RGB.cpp)
add_executable(RGB_test RGB_test.cpp)
target_link_libraries(RGB_test GTest::gtest_main RGB)

add_test(NAME RGBTest COMMAND rgb_test)
