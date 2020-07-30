cmake_minimum_required(VERSION 3.10)
enable_testing()

project(bowling)

set(FLAGS -Wall -Wextra -Werror -Wconversion -pedantic)

#################################################################
# Bowling's source files
set(SOURCES
    bowlingLane.cpp
    file.cpp
    game.cpp
    player.cpp
    validator.cpp)

# Tests' source files
set(TEST_SOURCES
    bowlingLane-ut.cpp
    file-ut.cpp
    game-ut.cpp
    player-ut.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#################################################################
# Download and unpack googletest at configure time
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


# Bowling's executable
add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

# Tests' executable
add_executable(${PROJECT_NAME}-ut ${TEST_SOURCES})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC ${PROJECT_NAME}-lib gtest_main)

add_test(NAME Test COMMAND ${PROJECT_NAME}-ut)
