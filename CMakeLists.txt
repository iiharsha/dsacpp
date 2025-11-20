cmake_minimum_required(VERSION 3.16)
project(dsacpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/solutions)

file(GLOB_RECURSE SOLUTION_SOURCES "solutions/**/**/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "tests/**/**/*.cpp")

find_package(Catch2 3 REQUIRED)

add_executable(tests
    ${SOLUTION_SOURCES}
    ${TEST_SOURCES}
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
