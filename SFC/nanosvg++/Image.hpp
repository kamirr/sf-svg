/* =========================================================== *
 * sf-svg (c) Kamil Koczurek | koczurekk@gmail.com             *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */
//! @file
//!
//! \brief
//! Nanosvg++ Image class declaration

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <SFML/System/Vector2.hpp>
#include <string>

#include "Nanosvg.hpp"

namespace nsvg {
	//! \class Image
	//!
	//! \brief C++-styled ImageStruct wrapper
	//!
	//! Provides object orientated interface for C-style nsvg::ImageStruct.
	class Image {
		cstyle::ImageStruct* internal = nullptr;

	public:
		//! \brief Parses SVG from file
		//!
		//! \param [in] filename – path to file
		//! \param [in] units – passed to nanosvg
		//! \param [in] dpi – passed to nanosvg
		//!
		//! \return True if ok, False otherwise
		bool loadFromFile(const std::string& filename, const std::string& units, const float dpi = 96.f) {
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

		//! \brief Parses SVG from memory
		//!
		//! \param [in] input – null-terminated data
		//! \param [in] units – passed to nanosvg
		//! \param [in] dpi – passed to nanosvg
		//!
		//! \return True if ok, False otherwise
		bool loadFromMemory(std::string input, const std::string& units, const float dpi = 96.f) {
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

		//! \brief Get internal image
		//!
		//! \return C-styled nsvg::ImageStruct
		cstyle::ImageStruct* getInternalImage() {
			return this->internal;
		}

		//! \brief Get shapes
		//!
		//! \return Shapes to process
		cstyle::Shape* getShapes() {
			return this->internal->shapes;
		}

		//! \brief Get size
		//!
		//! \return Image's size in sf::Vector2f
		sf::Vector2f getSize() const{
			return {
				this->internal->width,
				this->internal->height
			};
		}

		//! \brief Destructor
		//!
		//! Releases resources if any were allocated
		~Image() {
			if(internal)
				cstyle::deleteImage(internal);
		}
	};
}

#endif // IMAGE_HPP
