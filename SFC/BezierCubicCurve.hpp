#ifndef BEZIERCUBICCURVE_HPP
#define BEZIERCUBICCURVE_HPP
#include "BezierAbstractCurve.hpp"

namespace sfc
{
	class BezierCubicCurve
	: public BezierAbstractCurve
	{
	private:
		sf::Vertex debugLines[6];

		sf::Vector2f m_beginControl;
		sf::Vector2f m_endControl;

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	protected:
		void calculateCubic(std::vector<sf::Vector2f>&, const size_t, const float, sf::Vertex*);

	public:
		enum PointType {
			BEGIN_CONTROL,
			END_CONTROL,
			BEGIN,
			END
		};

		/* Constructors */
		BezierCubicCurve();
		BezierCubicCurve(const sf::Vector2f&, const sf::Vector2f&, const sf::Vector2f&, const sf::Vector2f&, DrawMode = NORMAL);

		/* Virtual methods */
		virtual Line2<float> getHelperLine(const float);
		virtual sf::Vector2f getPoint(const float);
		virtual void update();

		/* Class-definied API */
		void setPointPosition(PointType, sf::Vector2f);
		sf::Vector2f getPointPosition(PointType);

		Line2<float> getCubicHelperLine1(const float);
		Line2<float> getCubicHelperLine2(const float);
	};
}

#endif // BEZIERCUBICCURVE_HPP
