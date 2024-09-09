cmake_minimum_required(VERSION 3.23.2)

set(NAME tests)
project(${NAME})

set(CMAKE_C_STANDARD 17)

include_directories(deps/gtest)
include_directories(../include)

add_subdirectory(deps/gtest)

add_executable(test_square
	test_square.cpp
	../src/spiral_path.cpp
	../src/spiral_conditional.cpp
	../src/spiral_strategy.cpp
	../src/matrix_filling.cpp
)

add_executable(test_mxn
	test_mxn.cpp
	../src/spiral_path.cpp
	../src/spiral_conditional.cpp
	../src/spiral_strategy.cpp
	../src/matrix_filling.cpp
)

target_link_libraries(test_square gtest)
target_link_libraries(test_mxn gtest)
