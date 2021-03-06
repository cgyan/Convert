cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project(convert)
set(CMAKE_CXX_STANDARD 11)

set(GMOCK_LIB_NAME gmock)
set(GMOCK_INC_PATH /Users/iainhemstock/GitHub/googletest/googlemock/include)
set(GMOCK_LIB_PATH /Users/iainhemstock/GitHub/googletest/build/googlemock)

set(GTEST_LIB_NAME gtest)
set(GTEST_INC_PATH /Users/iainhemstock/GitHub/googletest/googletest/include)
set(GTEST_LIB_PATH /Users/iainhemstock/Github/googletest/build/googlemock/gtest)

include_directories(
        ${GMOCK_INC_PATH}
        ${GTEST_INC_PATH}
)

find_library(GMOCK_LIB
        NAMES ${GMOCK_LIB_NAME}
        PATHS ${GMOCK_LIB_PATH}
)

find_library(GTEST_LIB
        NAMES ${GTEST_LIB_NAME}
        PATHS ${GTEST_LIB_PATH}
)

add_executable(${CMAKE_PROJECT_NAME}
        main.cpp
        tests/tests.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${GMOCK_LIB}
        ${GTEST_LIB}
)
