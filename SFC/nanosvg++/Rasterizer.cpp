#include "Rasterizer.hpp"

namespace nsvg {
	Rasterizer::Rasterizer()
		: internal { cstyle::createRasterizer() }
	{ }

	Rasterizer::~Rasterizer() {
		cstyle::deleteRasterizer(this->internal);
	}

	sf::Image Rasterizer::rasterize(Image& image, float tx, float ty, float scale) {
		sf::Image img;

		sf::Uint8* pixels = new sf::Uint8[int(image.getSize().x * scale) * int(image.getSize().y * scale) * 4];
		nsvg::cstyle::rasterize(
			this->internal,
			image.getInternalImage(),
			tx,
			ty,
			scale,
			pixels,
			image.getSize().x * scale,
			image.getSize().y * scale,
			image.getSize().x * scale * 4
		);

		img.create(image.getSize().x * scale, image.getSize().y * scale, pixels);
		delete[] pixels;

		return img;
	}
}
