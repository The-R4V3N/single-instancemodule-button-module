cmake_minimum_required(VERSION 3.22.1)

set(PROJECT_NAME Assignment-2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

add_compile_definitions(DEVENV)

project(${PROJECT_NAME} VERSION 1.0
                        DESCRIPTION "Assignment-2"
                        HOMEPAGE_URL "oliver-joisten.se" 
                        LANGUAGES CXX)

#Build test_button
add_library(button OBJECT test/unity/unity.cpp test/test_button/bsp.cpp test/test_button/test.cpp)
target_include_directories(button PRIVATE test/unity test/test_button lib/button)

add_library(button_cov OBJECT lib/button/button.cpp)
target_include_directories(button_cov PRIVATE lib/button test/test_button)
target_compile_options(button_cov PRIVATE --coverage)

add_executable(button_test $<TARGET_OBJECTS:button> $<TARGET_OBJECTS:button_cov>)
target_link_options(button_test PRIVATE --coverage)

add_custom_target(coverage_test_button button_test
    COMMAND gcovr -r ${CMAKE_CURRENT_SOURCE_DIR} --html-details -o ${CMAKE_CURRENT_BINARY_DIR}/index.html
)