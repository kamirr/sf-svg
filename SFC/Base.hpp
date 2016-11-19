/* =========================================================== *
 * SF-Curves (c) Kamil Koczurek | koczurekk@gmail.com          *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef SFAS_BASE_HPP
#define SFAS_BASE_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>

namespace sfc {
	enum DrawMode {
		NORMAL,
		DEBUG
	};

	template<typename T>
	struct Line2
	: public sf::Drawable {
		sf::Vector2<T> point;
		sf::Vector2<T> vector;
		sf::Color color;

		Line2() {
			point = {0, 0};
			vector = {0, 0};
			color = {255, 255, 255};
		}
		Line2(sf::Vector2<T> point, sf::Vector2<T> vector, sf::Color color = {255, 255, 255}) {
			this->point = point;
			this->vector = vector;
			this->color = color;
		}

		T length() {
			return sqrt(vector.x * vector.x + vector.y * vector.y);
		}

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
			sf::Vertex tab[2] =
			{{point, this->color},
			{point + vector, this->color}};

			target.draw(tab, 2, sf::Lines, states);
		}
	};
}

#endif // SYSTEM_HPP
