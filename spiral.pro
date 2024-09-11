TEMPLATE = app

TARGET = spiral

QT += widgets

SOURCES += src/application.cpp src/main.cpp src/spiral_conditional.cpp src/spiral_path.cpp src/spiral_strategy.cpp src/window.cpp src/matrix_filling.cpp

HEADERS += include/application.hpp include/corner_points.hpp include/matrix.hpp \
	include/matrix_filling.hpp include/spiral_conditional.hpp include/spiral_path.hpp include/spiral_strategy.hpp include/window.hpp

CONFIG += c++20
CONFIG += debug_and_release

INCLUDEPATH += include
