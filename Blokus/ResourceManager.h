#ifndef RESOURCEMANAGER_H 
#define RESOURCEMANAGER_H 

#include <iostream>
#include "Resource/Fonts/Helvetica.hpp"
#include <SFML/Graphics.hpp>


class ResourceManager {
public:

	static ResourceManager& getInstance() {
		static ResourceManager instance;
		return instance;
	}

	static const std::unique_ptr<sf::RenderWindow>& getWindowPtr();
	static const sf::Font& getFont();

	// Delete copy constructor and assignment operator
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;


private:
	const std::string PROJECT_NAME = "Blokus";

	ResourceManager();

	sf::Font mFont;
	std::unique_ptr<sf::RenderWindow> mWindowPtr;

	const std::unique_ptr<sf::RenderWindow>& getWindowPtrImpl();
	const sf::Font& getFontImpl();

};

#endif

