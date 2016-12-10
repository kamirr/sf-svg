#ifndef RASTERIZER_HPP
#define RASTERIZER_HPP

#include <SFML/Graphics/Image.hpp>

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
