/* ====================================================== *
 * nanosvg++                                              *
 * This software is a fork of nanosvg (nanosvgrastr.hpp). *
 * No license-related aspects are affected.               *
 * Kamil Koczurek | koczurekk@gmail.com                   *
 * ====================================================== */
//! @file
//!
//! \brief
//! Path class declaration

#ifndef PATH_HPP
#define PATH_HPP

#include <SFML/System/Vector2.hpp>
#include <vector>

#include "nanosvg.hpp"

namespace nsvg {
	struct CubicPointSet {
		sf::Vector2f begin;
		sf::Vector2f end;

		sf::Vector2f control1;
		sf::Vector2f control2;
	};

	//! \class Path
	//!
	//! \brief C++-styled cstyle::PathStruct wrapper
	class Path {
	public:
		const cstyle::PathStruct* internal;

	public:
		//! \brief Constructor
		//!
		//! \param [in] ptr – const pointer to PathStruct
		//!
		//! It's the only constructor of nsvg::Path class, which wraps given cstyle::PathStruct into object orientated interface.
		Path(const cstyle::PathStruct* ptr);

		//! \brief Get points sets
		//!
		//! \return Set of points required to create Bezier curve (begin, end, 2 handles)
		//!
		//! Sample code:
		//! \code{.cpp}
		//! for(const auto& points: path.getPointsSets()){
		//! std::cout << "begin: [" << points.begin.x << ", " << points.begin.y << "]" << std::endl
		//! std::cout << "end: [" << points.end.x << ", " << points.end.y << "]" << std::endl
		//! std::cout << "handle 1: [" << points.control1.x << ", " << points.control1.y << "]" << std::endl
		//! std::cout << "handle 2: [" << points.control2.x << ", " << points.control2.y << "]" << std::endl
		//! }
		std::vector<CubicPointSet> getPointsSets() const;

		//! \brief Get next path
		//!
		//! \return Instance of shape wrapping this->internal->path.
		Path getNextPath() const;

		//! \brief Is ok?
		//!
		//! \return True if instance wraps proper pointer (not nullptr), False otherwise.
		bool good() const;

		//! \brief Switches itself to next path
		//!
		//! \return Reference to *this
		//!
		//! Equivalent to:
		//! \code{.cpp}
		//! samplePath = samplePath.getNextPath();
		//! \endcode
		Path& operator ++();
	};
}

#endif // PATH_HPP
