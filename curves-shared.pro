TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR=build-shared
OBJECTS_DIR=build-shared/obj

SOURCES += SFC/BezierAbstractCurve.cpp \
	SFC/BezierCubicCurve.cpp \
	SFC/BezierSquareCurve.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wno-narrowing
LIBS += -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
	SFC/BezierAbstractCurve.hpp \
	SFC/BezierCubicCurve.hpp \
	SFC/BezierCurve.hpp \
	SFC/BezierSquareCurve.hpp \
	SFC/VertexVector.hpp \
    SFC/Base.hpp
