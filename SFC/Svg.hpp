#ifndef SVG_HPP
#define SVG_HPP

//! \file
//! SVGImage class declaration

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <string>
#include <vector>
#include <memory>

#include "BezierCubicCurve.hpp"
#include "nanosvg.hpp"

namespace sfc {
	//! \class SVGImage
	//!
	//! \brief SVG-XML image support for SFML
	//!
	//! Class uses Cubic Bezier Curves to draw SVG graphics, can be drawn as set of curves or rasterized to create normal sf::Image.
	class SVGImage
	: public sf::Drawable {
		std::vector<std::shared_ptr<BezierCubicCurve>> curves;
		NSVGimage* image;

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	public:
		//! \brief Default Constructor
		//!
		//! Initializes internal variables
		SVGImage();

		//! \brief Constructor loading from file
		//!
		//! \param [in] file – path to .svg file
		//! \param [in] dpi – passed do nanosvg
		//!
		//! Calls loadFromFile with given params
		SVGImage(const std::string& file, const float dpi = 96.f);

		//! \brief Opens .svg file
		//!
		//! \param [in] file – path to .svg file
		//! \param [in] dpi – passed do nanosvg
		//!
		//! Method that parses .svg file and creates proper Bezier Curves.
		bool loadFromFile(const std::string& file, const float dpi = 96.f);

		//! \brief Destructors
		//!
		//! Releases resources (taken by nanosvg) if any image was loaded.
		~SVGImage();
	};
}

#endif // SVG_HPP
