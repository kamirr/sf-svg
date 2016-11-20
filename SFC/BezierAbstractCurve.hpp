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
	//! \class BezierAbstractCurve
	//!
	//! \brief Abstract Bezier curve class
	//!
	//! Do not define methods! <br />
	//! Inherit it to create class compatibile with Brezier Curve API.<br />
	//! Remember, it's not an interface, this class contains variables
	//! and some definied methods – getters & setters (mostly).
	class BezierAbstractCurve:
	public sf::Shape {
	protected:
		//! \brief Vertices used to draw curve
		VertexVector<sf::LinesStrip> m_vertices;

		//! \brief Stores points count
		std::size_t m_pointCount;

		//! \brief Curve's color
		sf::Color m_color;

		//! \brief First point of a curve
		sf::Vector2f m_begin;

		//! \brief Last point of a curve
		sf::Vector2f m_end;

		//! \brief Part of curve to be drawn
		//!
		//! Real number in range [0, 1], if set to .5 only 50% of curve will be drawn etc.
		float m_limitCurve;

		//! \brief Drawing mode
		//!
		//! NORMAL – Just draw curve <br />
		//! DEBUG – Draw also helper lines etc.
		DrawMode m_mode;

	public:
		//! \brief Get last line used to draw a curve
		//!
		//! Other helper lines are ignored, this function returns the one, on which "pencil" is placed.
		virtual Line2<float> getHelperLine(const float) const = 0;

		//! \brief Calculates vertices
		//!
		//! Changes are applied only when this function is called.
		//! \code{.cpp}
		//! sfc::BezierCubicCurve curve(arg1, arg2, arg3, arg4);
		//! curve.update();
		//! //...
		//! curve.setColor({68, 69, 70}); //Ignored
		//! window.draw(curve);
		//! \endcode
		virtual void update() = 0;

		//! \brief Returns point count
		virtual std::size_t getPointCount() const;

		//! \brief Virtual destructor
		//!
		//! Does nothing expect of ensuring that destructors of inherited classes will be called.
		virtual ~BezierAbstractCurve()
		{ }

		//! \brief Sets color
		//!
		//! Use to set color of curve's vertices.
		//! \code{.cpp}
		//! curve.setColor({255, 20, 20}); //Red
		//! \endcode
		void setColor(const sf::Color&);

		//! \brief Returns color of curve
		sf::Color getColor();

		//! \brief Set part of curve to be drawn
		//!
		//! \code{.cpp}
		//! curve.setNormalizedLengthLimit(.5f); //Draw 50% of the curve
		//! \endcode
		void setNormalizedLengthLimit(const float);

		//! \brief Get part of curve to be drawn
		//!
		//! Take a look at setNormalizedLengthLimit() and m_limitCurve.
		float getNormalizedLengthLimit();

		//! \brief Set amount of points to draw curve
		//!
		//! \code{.cpp}
		//! curve1.setPointCount(6); //Ugly one
		//! curve12.setPointCount(200); //OK in most cases
		//! curve2.setPointCount(6000); //Sooo good (actually too much)
		//! \endcode
		void setPointCount(const std::size_t);

		//! \brief Translate curve
		void move(sf::Vector2f);
	};
}
#endif // BEZIERABSTRACTCURVE_H
