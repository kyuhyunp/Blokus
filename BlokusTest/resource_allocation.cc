#include "../Blokus/ResourceHolder.h"
#include "../Blokus/ResourceIdentifiers.h"
#include "../Blokus/Sidebar.h"

namespace Resource {

	static std::unique_ptr<sf::RenderWindow> getWindowPtr(sf::Vector2u size) {
		auto windowPtr = std::make_unique <sf::RenderWindow>
			(sf::VideoMode(size, sf::Style::Resize | sf::Style::Close), "Test");
		return windowPtr;
	}

	static void loadResources(FontHolder& fonts) {
		fonts.open(Fonts::Helvetica, "../Blokus/Resource/Fonts/Helvetica.ttf");
	}

}
