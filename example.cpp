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

int main() {
	/* Enable antialiasing (optional) */
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	/* Create window */
	sf::RenderWindow app(sf::VideoMode(600, 600), "app", sf::Style::Default, settings);

	/* Vector to store pointers to shapes */
	std::vector<sf::Shape*> shapes;

	/* Create bezier curve */
	sfc::BezierCubicCurve c1(
	{200, 50}, {350, 500},
	{50, 50}, {50, 550},
	sfc::DEBUG);

	/* Push it's address to vector */
	shapes.push_back(&c1);

	/* Configure curve */
	c1.setNormalizedLengthLimit(1.f);
	c1.setPointCount(2048);
	c1.update();

	/* Create second bezier curve */
	sfc::BezierCubicCurve c2(
	{350, 500}, {200, 50},
	{500, 475}, {400, 50},
	sfc::DEBUG);

	/* Push it's address to vector */
	shapes.push_back(&c2);

	/* Configure it */
	c2.setNormalizedLengthLimit(1.f);
	c2.setPointCount(2048);
	c2.update();

	/* Create some circle shape */
	sf::CircleShape cs(20, 50);

	/* Push it's address to the same vector */
	shapes.push_back(&cs);

	/* Set position of circle */
	cs.setPosition(150, 90);

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
