#include "BezierAbstractCurve.hpp"

namespace sfc
{
	void BezierAbstractCurve::setColor(const sf::Color& color)
	{
		this->m_color = color;
	}
	sf::Color BezierAbstractCurve::getColor()
	{
		return this->m_color;
	}

	void BezierAbstractCurve::setNormalizedLengthLimit(const float limit)
	{
		this->m_limitCurve = limit;
	}
	float BezierAbstractCurve::getNormalizedLengthLimit()
	{
		return this->m_limitCurve;
	}

	void BezierAbstractCurve::setPointCount(const std::size_t count)
	{
		this->m_pointCount = count;
	}
	std::size_t BezierAbstractCurve::getPointCount()
	{
		return this->m_pointCount;
	}

	void BezierAbstractCurve::move(sf::Vector2f diff)
	{
		for(auto& verticle : m_vertices)
			verticle.position += diff;
	}
}
