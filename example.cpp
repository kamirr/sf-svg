#include "SFC/Svg.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int main() {
	/* Create image */
	sfc::SVGImage img;

	/* Load svg file */
	img.loadFromFile("nano.svg");

	/* Move it by [10, 10] to make it more visible */
	img.move({10, 10});

	/* Scale image */
	const auto imageScale = 2.5f;
	img.scale(imageScale);

	/* Rasterize using scale 2.f and save result (sf::Image) to file */
	img.rasterize(2.f).saveToFile("rasterized.png");

	/* Create window */
	sf::RenderWindow app(sf::VideoMode((img.getSize().x + 20) * imageScale, (img.getSize().y + 20) * imageScale), "sf-svg");

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
