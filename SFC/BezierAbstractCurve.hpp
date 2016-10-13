#ifndef BEZIERABSTRACTCURVE_H
#define BEZIERABSTRACTCURVE_H

#include <SFML/Graphics/Drawable.hpp>
#include "VertexVector.hpp"
#include "SfasBase.hpp"

/*
 * Abstract class!
 * Do not define methods!
 * Inherit it to create class compatibile with Brezier Curve API.
 *
 * Remember, it's not an interface, this class contains variables
 * and some definied methods – getters & setters (mostly).
*/
namespace sfc
{
class BezierAbstractCurve
: public sf::Drawable
{
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
	virtual Line2<float> getHelperLine(const float) = 0;
	virtual sf::Vector2f getPoint(const float) = 0;
	virtual void update() = 0;

	/* Definied methods */
	void setColor(const sf::Color&);
	sf::Color getColor();

	void setNormalizedLengthLimit(const float);
	float getNormalizedLengthLimit();

	void setPointCount(const std::size_t);
	std::size_t getPointCount();

	void move(sf::Vector2f);
};
}
#endif // BEZIERABSTRACTCURVE_H
