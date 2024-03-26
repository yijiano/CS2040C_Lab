cmake_minimum_required(VERSION 3.0.0)
project("CS2040C AY23/24 SEM2 ASSIGNMENT 2")

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

add_library(food food.cpp)

enable_testing()

add_executable(linked_list_test linked_list_test.cpp)
target_link_libraries(linked_list_test GTest::gtest_main)

add_test(NAME LinkedListTest COMMAND linked_list_test)

add_executable(food_test food_test.cpp)
target_link_libraries(food_test GTest::gtest_main food)

add_test(NAME FoodTest COMMAND food_test)
