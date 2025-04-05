#include <filesystem>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

using std::string;

const string QUIT_TEXT = "Quit";
const string HELVETICA_PATH = "../include/font/helvetica-255/Helvetica.ttf";
const string PROJECT_NAME = "Blokus";


// Header content goes here
inline bool bLoadFont(sf::Font& font, const string& fontPath);
sf::Text getQuitButton(sf::Font& font);
void pollEvents(const std::unique_ptr<sf::RenderWindow>& window, sf::Text& quitButton);


inline bool bLoadFont(sf::Font &font, const string &fontPath) {
	if (!font.openFromFile(fontPath)) {
		return false;
	}

	return true;
}

sf::Text getQuitButton(sf::Font &font) {
	sf::Text quitButton(font);
	quitButton.setString(QUIT_TEXT);
	quitButton.setCharacterSize(30);
	quitButton.setFillColor(sf::Color::Black);
	return quitButton;
}

void pollEvents(const std::unique_ptr<sf::RenderWindow>& window, sf::Text& quitButton) {
	while (const std::optional event = window->pollEvent()) {
		// Handle keys pressed
		if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
				window->close();
			}
		}

		// Handle mouse events using new Vector2 API and event system
		if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
			if (mousePressed->button != sf::Mouse::Button::Left) {
				continue;
			}

			const auto mousePos = sf::Vector2f{ 
				(float) mousePressed->position.x, 
				(float) mousePressed->position.y 
			};

			if (quitButton.getGlobalBounds().contains(mousePos)) {
				window->close();
			}
		}

		// Handle hover effect using a mouse cursor
		if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
			const auto mousePos = sf::Vector2f{
				(float)mouseMoved->position.x,
				(float)mouseMoved->position.y
			};

			const auto cursor = quitButton.getGlobalBounds().contains(mousePos) ?
				sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value() :
				sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
			
			window->setMouseCursor(cursor);
		}
	}
}

int main() {
	auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getFullscreenModes()[0], 
		PROJECT_NAME, 
		sf::State::Fullscreen);
	window->setVerticalSyncEnabled(true);


	// Load font
	sf::Font font;
	if (!bLoadFont(font, HELVETICA_PATH)) {
		std::cerr << "Error loading font from " + HELVETICA_PATH + "\n";
		return -1;
	}

	// Create buttons
	sf::Text quitButton = getQuitButton(font);

	while (window->isOpen()) {
		pollEvents(window, quitButton);

		window->clear(sf::Color::White);
		window->draw(quitButton);
		window->display();
	}

	return 0;
}