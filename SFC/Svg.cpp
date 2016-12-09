/* =========================================================== *
 * sf-svg (c) Kamil Koczurek | koczurekk@gmail.com          *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

//! @file
//!
//! \brief
//! SVGImage implementation

#include "Svg.hpp"

namespace sfc {
	/*
		Private
	*/
	void SVGImage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		for(const auto& curve: this->curves) {
			target.draw(*curve, states);
		}
	}

	void SVGImage::update() {
		this->curves.clear();

		for(auto shape = this->image.internal->shapes; shape != NULL; shape = shape->next) {
			for(auto path = shape->paths; path != NULL; path = path->next) {
				for(auto i = 0; i < path->npts - 1; i += 3) {
					float* p = &path->pts[i * 2];

					sf::Vector2f begin    = { p[0], p[1] };
					sf::Vector2f ctrl1    = { p[2], p[3] };
					sf::Vector2f ctrl2    = { p[4], p[5] };
					sf::Vector2f end     = { p[6], p[7] };

					this->curves.push_back(std::make_shared<BezierCubicCurve>(begin, end, ctrl1, ctrl2));
					(*this->curves.back()).setNormalizedLengthLimit(1.f);
					(*this->curves.back()).setPointCount(1024);
					(*this->curves.back()).update();
				}
			}
		}
	}

	/*
		Public
	*/
	SVGImage::SVGImage()
	{ }

	SVGImage::SVGImage(const std::string &file, const float dpi) {
		this->loadFromFile(file, dpi);
	}

	bool SVGImage::loadFromFile(const std::string &file, const float dpi) {
		if(!this->image.loadFromFile(file.c_str(), "px", dpi))
			return false;

		this->update();
		return true;
	}

	bool SVGImage::loadFromMemory(const void *data, size_t size, const float dpi) {
		if(static_cast<const sf::Uint8*>(data)[size - 1] != '\0') {
			std::cout << "SVG file in memory has to be null-terminated!" << std::endl;
			return false;
		}

		std::string copy = static_cast<const char*>(data);
		if(!this->image.loadFromMemory(copy, "px", dpi))
			return false;

		this->update();
		return true;
	}

	bool SVGImage::loadFromStream(sf::InputStream& stream, const float dpi) {
		char* copy = new char[stream.getSize() + 1];
		stream.read(copy, stream.getSize());

		if(copy[stream.getSize() - 1] != '\0') {
			copy[stream.getSize()] = '\0';
		}

		bool ok = this->image.loadFromMemory(copy, "px", dpi);
		delete[] copy;

		if(!ok)
			return false;

		this->update();
		return true;
	}

	sf::Image SVGImage::rasterize(const float scale) {
		nsvg::NSVGrasterizer* rasterizer = nsvg::nsvgCreateRasterizer();
		sf::Image img;

		sf::Uint8* pixels = new sf::Uint8[int(this->image.internal->height * scale) * int(this->image.internal->width * scale) * 4];
		nsvg::nsvgRasterize(rasterizer, this->image.internal, 0, 0, scale, pixels, this->image.internal->width * scale, this->image.internal->height * scale, this->image.internal->width * scale * 4);

		img.create(this->image.internal->width * scale, this->image.internal->height * scale, pixels);

		nsvg::nsvgDeleteRasterizer(rasterizer);
		return img;
	}

	void SVGImage::move(sf::Vector2f vec) {
		for(auto& curve: this->curves) {
			(*curve).move(vec);
		}
	}

	void SVGImage::scale(const float factor) {
		for(auto& curve: this->curves) {
			(*curve).scale({factor, factor});
		}
	}

	sf::Vector2f SVGImage::getSize() const {
		return {
			this->image.internal->width,
			this->image.internal->height
		};
	}
}
