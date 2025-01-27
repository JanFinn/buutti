cmake_minimum_required(VERSION 3.14)
project(buutti)

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

add_executable(
  deck_test
  ./tests/deck_test.cpp
)

add_executable(
  application
  main.cpp
)

add_compile_options(-Wall -Wextra -Wpedantic -Wno-dev)

target_link_libraries(
  deck_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(deck_test)
