#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "nanosvg.hpp"

namespace nsvg {
	class Shape {
		const cstyle::ShapeStruct* internal;

	public:
		Shape(const cstyle::ShapeStruct *ptr);

		std::string getId() const;

		cstyle::Paint getFill() const;

		cstyle::Paint getStroke() const;

		float getOpacity() const;

		float getStrokeWidth() const;

		float getStrokeDashOffset() const;

		const float* getStrokeDashArray() const;

		size_t getStrokeDashCount() const;

		LineJoin getStrokeLineJoin() const;

		LineCap getStrokeLineCap() const;

		Flags getFlags() const;

		const float* getBounds() const;

		const cstyle::Path* getPaths() const;

		Shape getNextShape() const;

		bool good() const {
			return internal;
		}
	};
}

#endif // SHAPE_HPP
