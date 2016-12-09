TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wno-narrowing
LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += example.cpp \
	SFC/BezierAbstractCurve.cpp \
	SFC/BezierCubicCurve.cpp \
	SFC/BezierSquareCurve.cpp \
    SFC/Svg.cpp \
    SFC/nanosvg++/Nanosvg.cpp \
    SFC/nanosvg++/Nanosvgrastr.cpp \
    SFC/nanosvg++/Image.cpp

HEADERS += \
	SFC/BezierAbstractCurve.hpp \
	SFC/BezierCubicCurve.hpp \
	SFC/BezierCurve.hpp \
	SFC/BezierSquareCurve.hpp \
	SFC/VertexVector.hpp \
    SFC/Base.hpp \
    SFC/Svg.hpp \
    SFC/debug.hpp \
    SFC/nanosvg++/Image.hpp \
    SFC/nanosvg++/Nanosvg.hpp \
    SFC/nanosvg++/Nanosvgrastr.hpp \
    SFC/nanosvg++/Nsvgpp.hpp
