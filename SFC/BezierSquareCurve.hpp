#ifndef BEZIERSQUARECURVE_H
#define BEZIERSQUARECURVE_H
#include "BezierAbstractCurve.hpp"

namespace sfc
{
	class BezierSquareCurve
	: public BezierAbstractCurve
	{
	private:
		sf::Vertex m_debugLines[4];
		sf::Vector2f m_controlPoint;

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	protected:
		void calculateSquare(std::vector<sf::Vector2f>&, const size_t, const float, sf::Vertex*);

	public:
		enum PointType {
			CONTROL,
			BEGIN,
			END
		};

		/* Constructors */
		BezierSquareCurve();
		BezierSquareCurve(const sf::Vector2f&, const sf::Vector2f&, const sf::Vector2f&, DrawMode = NORMAL);

		/* Virtual methods */
		virtual Line2<float> getHelperLine(const float);
		virtual sf::Vector2f getPoint(const float);
		virtual void update();

		/* Class-definied API */
		void setPointPosition(PointType, sf::Vector2f);
		sf::Vector2f getPointPosition(PointType);
	};
}

#endif // BEZIERSQUARECURVE_H
