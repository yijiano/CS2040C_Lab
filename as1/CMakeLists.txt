cmake_minimum_required(VERSION 3.0.0)
project("CS2040C AY23/24 SEM2 ASSIGNMENT 1")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_COLOR_DIAGNOSTICS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(linked_list linked_list.cpp)
add_executable(linked_list_test linked_list_test.cpp)
target_link_libraries(linked_list_test GTest::gtest_main linked_list)

include(GoogleTest)
gtest_discover_tests(linked_list_test)
