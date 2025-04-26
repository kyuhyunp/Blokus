#ifndef SCENE_H 
#define SCENE_H 

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include <SFML/Graphics.hpp>

enum class SceneType {
	Menu,
	Settings
};// TODO: make more types like Game, Settings, End

class Scene {
public:
	Scene(sf::RenderWindow& window, FontHolder& fonts);

	virtual void draw();
	void draw(const sf::Drawable& drawable);
	void resize();
	virtual void update(const sf::Event& event);
	
private:
	// Shared Resources
	sf::RenderWindow& mWindow;
	FontHolder& mFonts;

	// Resource access
	unsigned int getHeight() const;

	// Event handling
	void handleHoverEffect(const sf::Event& event);
	void handleResizedWindow(const sf::Event& event);
};

#endif

