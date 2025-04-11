#ifndef SIDEBAR_H 
#define SIDEBAR_H 

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class Sidebar {
public:
	// Static method to get the instance
	static Sidebar& getInstance() {
		static Sidebar instance;
		return instance;
	}

	void resize();
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

	// Member variables
	sf::Text mBlokusButton;
	sf::Text mSettingsButton;
	sf::Text mQuitButton;
	sf::RectangleShape mBorder;

	// Private constructor
	Sidebar();

	// Delete copy constructor and assignment operator
	Sidebar(const Sidebar&) = delete;
	Sidebar& operator=(const Sidebar&) = delete;

	// Helper methods
	unsigned int getHeight() const;
	void setBlokusButton();
	void setSettingsButton();
	void setQuitButton();
	void updateQuitButtonPosition();
	void updateBorder();
};

#endif

