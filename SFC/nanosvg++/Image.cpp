#include "Image.hpp"

namespace nsvg {
	bool Image::loadFromFile(const std::string& filename, const std::string& units, const float dpi) {
		if(internal)
			cstyle::deleteImage(internal);

		internal = cstyle::parseFromFile(filename.c_str(), units.c_str(), dpi);

		if(!this->internal) {
			std::cout << "Couldn't parse SVG image!" << std::endl;
			this->internal = nullptr;
			return false;
		}

		return true;
	}

	bool Image::loadFromMemory(std::string input, const std::string& units, const float dpi) {
		if(internal)
			cstyle::deleteImage(internal);

		internal = cstyle::parse(&input[0], units.c_str(), dpi);

		if(!this->internal) {
			std::cout << "Couldn't parse SVG image!" << std::endl;
			this->internal = nullptr;
			return false;
		}

		return true;
	}

	cstyle::ImageStruct* Image::getInternalImage() {
		return this->internal;
	}

	cstyle::ShapeStruct* Image::getFirstShape() {
		return this->internal->shapes;
	}

	sf::Vector2f Image::getSize() const {
		return {
			this->internal->width,
			this->internal->height
		};
	}

	Image::~Image() {
		if(internal)
			cstyle::deleteImage(internal);
	}
}
