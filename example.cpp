#include "SFC/BezierCurve.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

/* Functions converting sf::Shape ptrs to more specific ones */
std::shared_ptr<sfc::BezierAbstractCurve> shapeToCurve(std::shared_ptr<sf::Shape> ptr) {
	return std::dynamic_pointer_cast<sfc::BezierAbstractCurve>(ptr);
}
std::shared_ptr<sf::CircleShape> shapeToCircle(std::shared_ptr<sf::Shape> ptr) {
	return std::dynamic_pointer_cast<sf::CircleShape>(ptr);
}

int main() {
	/* Enable antialiasing (optional) */
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	settings.attributeFlags = sf::ContextSettings::Debug;

	/* Create window */
	sf::RenderWindow app(sf::VideoMode(600, 600), "app", sf::Style::Default, settings);

	/* Vector storing shared_ptrs to any sf::Shape */
	std::vector<std::shared_ptr<sf::Shape>> shapes;

	/* Push back BezierCubicCurve shared ptr */
	shapes.push_back(
	std::make_shared<sfc::BezierCubicCurve>(sfc::BezierCubicCurve(
	{200, 50}, {350, 500},
	{50, 50}, {50, 550},
	sfc::DEBUG)));

	/* Dynamically cast sf::Shape* to
	 * sf::AbstractBezierCurve*, so those functions could be used */
	(*shapeToCurve(shapes[0])).setNormalizedLengthLimit(1.f);
	(*shapeToCurve(shapes[0])).setPointCount(2048);
	(*shapeToCurve(shapes[0])).update();

	/* Push back another BezierCubicCurve shared ptr */
	shapes.push_back(
	std::make_shared<sfc::BezierCubicCurve>(
	sfc::BezierCubicCurve(
	{350, 500}, {200, 50},
	{500, 475}, {400, 50},
	sfc::DEBUG)));

	/* And again dynamically cast sf::Shape* to
	 * sf::AbstractBezierCurve*, so those functions could be used */
	(*shapeToCurve(shapes[1])).setNormalizedLengthLimit(1.f);
	(*shapeToCurve(shapes[1])).setPointCount(2048);
	(*shapeToCurve(shapes[1])).update();

	/* Push another class that inherits sf::Shape */
	shapes.push_back(std::make_shared<sf::CircleShape>(sf::CircleShape(20, 50)));

	/* Any sf::Shape has this function, but
	 * those can't work while using curves */
	(*shapes[2]).setPosition(150, 90);

	/* Main loop */
	while(app.isOpen()) {
		/* Handle events */
		for(sf::Event ev; app.pollEvent(ev);) {
			if(ev.type == sf::Event::Closed)
				app.close();
		}

		/* Clear window */
		app.clear({20, 20, 20});

		/* Draw shapes at once, no need to know whether it
		 * is sfc::BezierCubicCurve or sf::CircleShape */
		for(const auto ptr: shapes)
			app.draw(*ptr);

		/* Display */
		app.display();
	}
	return 0;
}
