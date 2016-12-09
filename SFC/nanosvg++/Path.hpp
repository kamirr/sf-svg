#ifndef PATH_HPP
#define PATH_HPP

#include <SFML/System/Vector2.hpp>
#include <vector>

#include "nanosvg.hpp"

/*
	struct PathStruct
	{
		float* pts;					// Cubic bezier points: x0,y0, [cpx1,cpx1,cpx2,cpy2,x1,y1], ...
		int npts;					// Total number of bezier points.
		char closed;				// Flag indicating if shapes should be treated as closed.
		float bounds[4];			// Tight bounding box of the shape [minx,miny,maxx,maxy].

		PathStruct* next;		// Pointer to next path, or NULL if last element.
	};
*/
namespace nsvg {
	struct CubicPointSet {
		sf::Vector2f begin;
		sf::Vector2f end;

		sf::Vector2f control1;
		sf::Vector2f control2;
	};

	class Path {
	public:
		const cstyle::PathStruct* internal;

	public:
		Path(const cstyle::PathStruct* ptr);

		std::vector<CubicPointSet> getPointsSets() const;

		Path getNextPath() const;

		bool good() const;

		Path& operator ++();
	};
}

#endif // PATH_HPP
