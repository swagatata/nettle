cmake_minimum_required(VERSION 3.14)
project(nettle)

set(CMAKE_CXX_STANDARD 17)

find_library(GTEST_LIBRARIES
             NAMES gtest gtest_main
             HINTS /usr/local/lib)

find_path(GTEST_INCLUDE_DIRS
          NAMES gtest/gtest.h
          HINTS /usr/local/include/)

message(STATUS "GTest include directories: ${GTEST_INCLUDE_DIRS}")
message(STATUS "GTest library directories: ${GTEST_LIBRARY_DIRS}")
message(STATUS "GTest libraries: ${GTEST_LIBRARIES}")

# Add the include directory
include_directories(include)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the source files
add_library(nettle src/laver_table.cpp)
# add_library(atlassian src/atlassian.cpp)
add_executable(laver_table.t.tsk test/laver_table.t.cpp)
# add_executable(atlassian.t.tsk tests/atlassian.t.cpp)
target_link_libraries(laver_table.t.tsk nettle ${GTEST_LIBRARIES} pthread)
# target_link_libraries(atlassian.t.tsk interviews ${GTEST_LIBRARIES} pthread)

# Add the test target
add_test(NAME laver_table COMMAND laver_table.t.tsk)
# add_test(NAME atlassian COMMAND atlassian.t.tsk)