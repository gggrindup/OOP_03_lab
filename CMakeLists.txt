cmake_minimum_required(VERSION 3.16)

project(oop_lab_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(figures
    src/figure_array.cpp
    src/figure.cpp
    src/point.cpp 
    src/rectangle.cpp
    src/square.cpp
    src/trapezoid.cpp
)
target_include_directories(figures PUBLIC include)

add_executable(03_lab_app src/main.cpp)
target_link_libraries(03_lab_app PRIVATE figures)

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests tests/test_figures.cpp)
target_link_libraries(run_tests PRIVATE gtest_main figures)
add_test(NAME unit_tests COMMAND run_tests)