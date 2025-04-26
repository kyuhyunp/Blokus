#ifndef SIDEBAR_H 
#define SIDEBAR_H 

#include <SFML/Graphics.hpp>
#include "ResourceIdentifiers.h"
#include "ResourceHolder.h"
#include "SFMLUtils.h";


class Sidebar {
public:

	Sidebar(sf::RenderWindow& window, FontHolder& fonts);

	// Delete copy constructor and assignment operator
	Sidebar(const Sidebar&) = delete;
	Sidebar& operator=(const Sidebar&) = delete;

	void resize();
	void draw();
	void update(const sf::Event& event);
	bool isWithinQuitButton(const sf::Vector2f& mousePos) const;


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
	FontHolder& mFonts;

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
	void setBorder();
	void updateQuitButtonPosition();
	void updateBorder();
};

#endif

