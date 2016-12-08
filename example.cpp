#include "SFC/Svg.hpp"

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
	settings.antialiasingLevel = 8;
	settings.depthBits = 24;

	/* Create window */
	sf::RenderWindow app(sf::VideoMode(800, 600), "app", sf::Style::Default, settings);

	sfc::SVGImage img;
	img.loadFromFile("nano.svg", 120);

	auto i = 0u;
	while(app.isOpen()) {
		/* Handle events */
		for(sf::Event ev; app.pollEvent(ev);) {
			if(ev.type == sf::Event::Closed) {
				app.close();
			} else if(ev.type == sf::Event::MouseButtonPressed) {
				++i;
			}
		}

		/* Clear window */
		app.clear({20, 20, 20});

		/* Draw SVG file */
		app.draw(img);

		/* Display */
		app.display();
	}
	return 0;
}
