#include "SFC/Svg.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int main() {
	/* Create image */
	sfc::SVGImage img;

	/* Load SVG image from file */
	img.loadFromFile("media/car.svg");

	/* Move it by [10, 10] to make it more visible */
	img.move({10, 10});

	/* Create window */
	sf::RenderWindow app(sf::VideoMode((img.getSize().x + 20) * 1, (img.getSize().y + 20) * 1), "sf-svg");

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
