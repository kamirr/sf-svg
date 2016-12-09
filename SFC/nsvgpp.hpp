#ifndef NSVGPP_H
#define NSVGPP_H

#include <SFML/System/Vector2.hpp>
#include <string>

#include "nanosvg.hpp"

namespace nsvg {
	class ImageC {
		Image* internal = nullptr;

	public:
		~ImageC() {
			if(internal)
				nsvg::deleteImage(internal);
		}

		bool loadFromFile(const std::string& filename, const std::string& units, const float dpi = 96.f) {
			if(internal)
				nsvg::deleteImage(internal);

			internal = parseFromFile(filename.c_str(), units.c_str(), dpi);

			if(!this->internal) {
				std::cout << "Couldn't parse SVG image!" << std::endl;
				this->internal = nullptr;
				return false;
			}

			return true;
		}

		bool loadFromMemory(std::string input, const std::string& units, const float dpi = 96.f) {
			if(internal)
				nsvg::deleteImage(internal);

			internal = parse(&input[0], units.c_str(), dpi);

			if(!this->internal) {
				std::cout << "Couldn't parse SVG image!" << std::endl;
				this->internal = nullptr;
				return false;
			}

			return true;
		}

		Image* getInternalImage() {
			return this->internal;
		}

		Shape* getShapes() {
			return this->internal->shapes;
		}

		sf::Vector2f getSize() const{
			return {
				this->internal->width,
				this->internal->height
			};
		}
	};
}

#endif // NSVGPP_H
