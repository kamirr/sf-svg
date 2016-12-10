/* ====================================================== *
 * nanosvg++                                              *
 * This software is a fork of nanosvg (nanosvgrastr.hpp). *
 * No license-related aspects are affected.               *
 * Kamil Koczurek | koczurekk@gmail.com                   *
 * ====================================================== */
//! @file
//!
//! \brief
//! Rasterizer class declaration

#ifndef RASTERIZER_HPP
#define RASTERIZER_HPP

#include <SFML/Graphics/Image.hpp>
#include <vector>

#include "nanosvgrastr.hpp"
#include "nanosvg.hpp"
#include "Image.hpp"

namespace nsvg {
	class Rasterizer {
		cstyle::RasterizerStruct* internal;

	public:
		Rasterizer();
		~Rasterizer();

		sf::Image rasterize(Image& image, float tx, float ty, float scale);
	};
}

#endif // RASTERIZER_HPP
