cmake_minimum_required(VERSION 3.10)

project(test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

set(
    TEST_SOURCES
    tests/test.cpp
    src/FearOfNumbers.cpp
    src/FearOfNumbers.h
)

add_executable(
    tests
    ${TEST_SOURCES}
)

target_include_directories(
    tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_link_libraries(
    tests
    gtest 
    gtest_main
)

enable_testing()

add_test(NAME FearOfNumbersTest COMMAND tests)

target_compile_options(
    tests PRIVATE
    -Wall
    -pedantic
)