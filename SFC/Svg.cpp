/* =========================================================== *
 * sf-svg (c) Kamil Koczurek | koczurekk@gmail.com          *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */
//! @file
//! SVGImage implementation

#include "Svg.hpp"

namespace sfc {
	SVGImage::SVGImage()
		: image { nullptr }
	{ }

	SVGImage::SVGImage(const std::string &file, const float dpi) {
		this->loadFromFile(file, dpi);
	}

	bool SVGImage::loadFromFile(const std::string &file, const float dpi) {
		if(this->image)
			nsvgDelete(this->image);

		this->image = nsvg::nsvgParseFromFile(file.c_str(), "px", dpi);

		if(this->image == NULL)
			this->image = nullptr;

		if(!this->image) {
			std::cout << "Couldn't open SVG image!" << std::endl;
			return false;
		}

		this->curves.clear();
		for(auto shape = this->image->shapes; shape != NULL; shape = shape->next) {
			for(auto path = shape->paths; path != NULL; path = path->next) {
				for(auto i = 0; i < path->npts - 1; i += 3) {
					float* p = &path->pts[i * 2];

					sf::Vector2f begin    = { p[0], p[1] };
					sf::Vector2f ctrl1    = { p[2], p[3] };
					sf::Vector2f ctrl2    = { p[4], p[5] };
					sf::Vector2f end     = { p[6], p[7] };

					this->curves.push_back(std::make_shared<BezierCubicCurve>(begin, end, ctrl1, ctrl2));
					(*this->curves.back()).setNormalizedLengthLimit(1.f);
					(*this->curves.back()).setPointCount(2048);
					(*this->curves.back()).update();
				}
			}
		}

		return true;
	}

	void SVGImage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		for(const auto& curve: this->curves) {
			target.draw(*curve, states);
		}
	}

	SVGImage::~SVGImage() {
		if(this->image)
			nsvgDelete(this->image);
	}
}
