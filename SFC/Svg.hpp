#ifndef SVG_HPP
#define SVG_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "BezierCubicCurve.hpp"
#include "nanosvg.hpp"

namespace sfc {
	class SVGImage
	: public sf::Drawable {
		std::vector<std::shared_ptr<BezierCubicCurve>> curves;
		NSVGimage* image;

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	public:
		SVGImage();
		SVGImage(const std::string& file, const float dpi = 96.f);
		bool open(const std::string& file, const float dpi = 96.f);

		~SVGImage();
	};
}

#endif // SVG_HPP
