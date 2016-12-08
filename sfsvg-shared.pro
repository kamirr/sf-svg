TEMPLATE = lib
TARGET = sfsvg

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR=build-shared
OBJECTS_DIR=build-shared/obj

QMAKE_CXXFLAGS += -std=c++11 -Wno-narrowing
LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += example.cpp \
	SFC/BezierAbstractCurve.cpp \
	SFC/BezierCubicCurve.cpp \
	SFC/BezierSquareCurve.cpp \
    SFC/Svg.cpp \
    SFC/nanosvg.cpp \
    SFC/nanosvgrastr.cpp

HEADERS += \
	SFC/BezierAbstractCurve.hpp \
	SFC/BezierCubicCurve.hpp \
	SFC/BezierCurve.hpp \
	SFC/BezierSquareCurve.hpp \
	SFC/VertexVector.hpp \
    SFC/Base.hpp \
    SFC/nanosvg.hpp \
    SFC/Svg.hpp \
    SFC/debug.hpp \
    SFC/nanosvgrastr.hpp
