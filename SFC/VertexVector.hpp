/* =========================================================== *
 * SF-Curves (c) Kamil Koczurek | koczurekk@gmail.com          *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef VERTEXVECTOR
#define VERTEXVECTOR

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <vector>

namespace sfc {
	template<sf::PrimitiveType TPrimitive>
	struct VertexVector
	: public std::vector<sf::Vertex>,
	public sf::Drawable {
		using std::vector<sf::Vertex>::vector;

		virtual void draw(sf::RenderTarget& mRenderTarget, sf::RenderStates mRenderStates) const {
			mRenderTarget.draw(&this->operator [](0), this->size(), TPrimitive, mRenderStates);
		}
	};
}
#endif
