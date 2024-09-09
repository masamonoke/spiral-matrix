cmake_minimum_required(VERSION 3.23.2)

set(NAME spiral)
project(${NAME})

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

enable_testing()
add_subdirectory(test)

add_test(NAME square_matrix COMMAND test_square)
add_test(NAME mxn_matrix COMMAND test_mxn)

find_package(Qt6 COMPONENTS Widgets QUIET)
if (NOT Qt6_FOUND)
    message(STATUS "Qt6 not found. Trying to find Qt5.")
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(QT_VERSION_MAJOR 5)
	set(CMAKE_AUTOMOC ON)
	set(CMAKE_AUTORCC ON)
	set(CMAKE_AUTOUIC ON)
else()
    set(QT_VERSION_MAJOR 6)
	qt_standard_project_setup()
endif()

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/spiral_strategy.cpp
	src/spiral_conditional.cpp
	src/spiral_path.cpp
	src/matrix_filling.cpp
	include/window.hpp # adding this for qt moc and for now dont know workaround
	src/window.cpp
	src/application.cpp
)

if (QT_VERSION_MAJOR EQUAL 6)
	target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
elseif (QT_VERSION_MAJOR EQUAL 5)
	target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
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
