#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

#include "nanosvg.hpp"

/*
	struct ShapeStruct
	{
		char id[64];				// Optional 'id' attr of the shape or its group
		Paint fill;				// Fill paint
		Paint stroke;			// Stroke paint
		float opacity;				// Opacity of the shape.
		float strokeWidth;			// Stroke width (scaled).
		float strokeDashOffset;		// Stroke dash offset (scaled).
		float strokeDashArray[8];			// Stroke dash array (scaled).
		char strokeDashCount;				// Number of dash values in dash array.
		LineJoin strokeLineJoin;		// Stroke join type.
		LineCap strokeLineCap;			// Stroke cap type.
		FillRule fillRule;				// Fill rule, see NSVGfillRule.
		Flags flags;		// Logical or of NSVG_FLAGS_* flags
		float bounds[4];			// Tight bounding box of the shape [minx,miny,maxx,maxy].

		Path* paths;			// Linked list of paths in the image.
		ShapeStruct* next;		// Pointer to next shape, or NULL if last element.
	};
*/

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
