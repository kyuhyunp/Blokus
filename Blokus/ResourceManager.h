#ifndef RESOURCEMANAGER_H 
#define RESOURCEMANAGER_H 

#include <iostream>
#include "Resource/Fonts/Helvetica.hpp"
#include <SFML/Graphics.hpp>


class ResourceManager {
public:
	ResourceManager();

	const std::unique_ptr<sf::RenderWindow>& getWindowPtr() const;
	const sf::Font& getFont() const;


	// Delete copy constructor and assignment operator
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;


private:
	const std::string PROJECT_NAME = "Blokus";

	sf::Font mFont;
};

#endif

