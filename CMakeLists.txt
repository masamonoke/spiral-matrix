cmake_minimum_required(VERSION 3.23.2)

set(NAME spiral)
project(${NAME})

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

enable_testing()
add_subdirectory(test)

add_test(NAME square_matrix COMMAND test_square)
add_test(NAME mxn_matrix COMMAND test_mxn)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/spiral_strategy.cpp
	src/spiral_conditional.cpp
	src/spiral_path.cpp
	src/matrix_filling.cpp
)

if (NOT MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE -Waddress -Wall -Warray-bounds -Wbool-operation -Wchar-subscripts -Wcomment
		-Wmisleading-indentation -Wparentheses -Wextra -pedantic -Wstrict-prototypes -Wshadow -Wconversion -Wvla -Wdouble-promotion -Wmissing-noreturn
		-Wmissing-format-attribute -Wmissing-prototypes -Wunused-result)
endif()

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
	if (NOT WIN32)
		target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
	endif()
	target_compile_definitions(${PROJECT_NAME} PUBLIC DEBUG=ON)
endif()
