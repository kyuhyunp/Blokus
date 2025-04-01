#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

int main() {
	unsigned int width = 640;
	unsigned height = 360;

	auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ width, height }), "Blokus");

	while (window->isOpen()) {
		while (const std::optional event = window->pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window->close();
			}
		}

		window->clear();
		window->display();
	}

	return 0;
}