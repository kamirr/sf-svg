TEMPLATE = lib
TARGET = sfsvg

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR=build-shared
OBJECTS_DIR=build-shared/obj

QMAKE_CXXFLAGS += -std=c++11 -Wno-narrowing
LIBS += -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    SFC/VertexVector.hpp \
    SFC/Svg.hpp \
    SFC/debug.hpp \
    SFC/BezierSquareCurve.hpp \
    SFC/BezierCurve.hpp \
    SFC/BezierCubicCurve.hpp \
    SFC/BezierAbstractCurve.hpp \
    SFC/Base.hpp \
    SFC/nanosvg++/Shape.hpp \
    SFC/nanosvg++/Rasterizer.hpp \
    SFC/nanosvg++/Path.hpp \
    SFC/nanosvg++/nsvgpp.hpp \
    SFC/nanosvg++/nanosvgrastr.hpp \
    SFC/nanosvg++/nanosvg.hpp \
    SFC/nanosvg++/Image.hpp \
    SFC/nanosvg++/enums.hpp

SOURCES += \
    SFC/Svg.cpp \
    SFC/BezierSquareCurve.cpp \
    SFC/BezierCubicCurve.cpp \
    SFC/BezierAbstractCurve.cpp \
    SFC/nanosvg++/Shape.cpp \
    SFC/nanosvg++/Rasterizer.cpp \
    SFC/nanosvg++/Path.cpp \
    SFC/nanosvg++/Nanosvgrastr.cpp \
    SFC/nanosvg++/Nanosvg.cpp \
    SFC/nanosvg++/Image.cpp
