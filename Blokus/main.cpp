#include "GameEngine.h"

#include <iostream>
#include "Resource/Fonts/Helvetica.hpp"



const std::string PROJECT_NAME = "Blokus";

int main() {
#ifdef _DEBUG
	auto windowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode({ 360, 600 }, 
		sf::Style::Resize | sf::Style::Close),
		PROJECT_NAME);
#else
	auto windowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode::getFullscreenModes()[0],
		PROJECT_NAME, sf::State::Fullscreen);
#endif

	windowPtr->setVerticalSyncEnabled(true);

	sf::Font helveticaFont;
	if (!helveticaFont.openFromMemory(&helvetica_255_Helvetica_ttf, helvetica_255_Helvetica_ttf_len)) {
		std::cerr << "Error loading font Helvetica\n";
		return -1;
	}

	GameEngine engine(helveticaFont, windowPtr);
	engine.run();

	return 0;
}