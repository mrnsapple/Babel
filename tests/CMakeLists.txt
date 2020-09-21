cmake_minimum_required(VERSION 3.7.2)
project(unit_tests)

#set(INCLUDE_DIR ../include)
#include_directories(unit_tests ${INCLUDE_DIR})


find_package(Threads REQUIRED)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)



# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

set(OG_SRC
#        ${INCLUDE_DIR}/header.hpp
        )

set(TEST_SRC unit_main.cpp unit_header.hpp
        )

SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

set(CMAKE_MODULE_PATH  ${unit_tests_SOURCE_DIR})
add_executable(unit_tests ${OG_SRC} ${TEST_SRC})

target_link_libraries(unit_tests  gtest_main  ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME unit_test_ex COMMAND unit_tests)
