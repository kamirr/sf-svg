/* =========================================================== *
 * SF-Curves (c) Kamil Koczurek | koczurekk@gmail.com          *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

//! @file
//! BezierAbstractCurve declaration and partial implementation.


/*! \mainpage SF-Curves
 *
 * \section About
 * SFML-related library adding Bezier curves (Cubic and Square) and API allowing writing new compatibile classes.
 *
 * \section Installation
 * Copy SFC directory (separated compilation will be available… soon).
 *
 * \section Usage
 * Add all files to project and include needed headers.
 *
 * \section Features
 * - Classes inherit sf::Shape;
 * - Implements Square- and Cubic curves;
 * - Provides interface for Bézier curves;
 * - Provides debug-friendly features like "helper lines" etc.
 */

#ifndef BEZIERABSTRACTCURVE_H
#define BEZIERABSTRACTCURVE_H

#include <SFML/Graphics/Shape.hpp>
#include "VertexVector.hpp"
#include "Base.hpp"

/*
 * Abstract class!
 * Do not define methods!
 * Inherit it to create class compatibile with Brezier Curve API.
 *
 * Remember, it's not an interface, this class contains variables
 * and some definied methods – getters & setters (mostly).
*/
namespace sfc {
class BezierAbstractCurve:
	public sf::Shape {
	protected:
		VertexVector<sf::LinesStrip> m_vertices;

		std::size_t m_pointCount;
		sf::Color m_color;

		sf::Vector2f m_begin;
		sf::Vector2f m_end;

		float m_limitCurve;
		DrawMode m_mode;

	public:
		/* Purely abstract methods */
		virtual Line2<float> getHelperLine(const float) const = 0;
		virtual void update() = 0;

		/* Definied abstract methods */
		virtual std::size_t getPointCount() const;
		virtual ~BezierAbstractCurve()
		{ }

		/* Definied methods */
		void setColor(const sf::Color&);
		sf::Color getColor();

		void setNormalizedLengthLimit(const float);
		float getNormalizedLengthLimit();

		void setPointCount(const std::size_t);
		void move(sf::Vector2f);
	};
}
#endif // BEZIERABSTRACTCURVE_H
