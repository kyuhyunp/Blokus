#ifndef SIDEBAR_H 
#define SIDEBAR_H 

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class Sidebar {
public:
	Sidebar(sf::RenderWindow& window, const ResourceManager& resourceManager);

	// Delete copy constructor and assignment operator
	Sidebar(const Sidebar&) = delete;
	Sidebar& operator=(const Sidebar&) = delete;

	virtual void resize();
	bool isWithinQuitButton(const sf::Vector2f& mousePos) const;
	void draw();


private:
	// const variables
	const int WIDTH = 150;
	const int TEXT_SIZE = 15;
	const float BUTTON_SPACING = 50.0f; 
	
	const std::string BLOKUS_TEXT = "Blokus";
	const std::string SETTINGS_TEXT = "Settings";
	const std::string QUIT_TEXT = "Quit";

	// Shared Resources
	sf::RenderWindow& mWindow;
	const sf::Font &mFont;
	const ResourceManager& mResourceManager;

	// Member variables
	sf::Text mBlokusButton;
	sf::Text mSettingsButton;
	sf::Text mQuitButton;
	sf::RectangleShape mBorder;

	// Helper methods
	unsigned int getHeight() const;
	void setBlokusButton();
	void setSettingsButton();
	void setQuitButton();
	void updateQuitButtonPosition();
	virtual void updateBorder();
};

#endif

