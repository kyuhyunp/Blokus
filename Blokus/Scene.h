#ifndef SCENE_H 
#define SCENE_H 

#include "Sidebar.h"
#include "SFMLUtils.h"

enum class SceneType {
	Menu,
	Settings
};// TODO: make more types like Game, Settings, End

class Scene {
public:
	Scene(sf::RenderWindow& window, Sidebar& sidebar, const ResourceManager& resourceManager);
	virtual void update(const sf::Event& event);
	virtual void draw();
	void draw(const sf::Drawable& drawable);
	

private:
	// Shared Resources
	sf::RenderWindow& mWindow;
	const sf::Font &mFont;
	const ResourceManager& mResourceManager;

	// Member variable
	Sidebar& mSidebar;

	// Resource access
	unsigned int getHeight() const;

	// State management
	void resize();

	// Event handling
	void handleWindowClosure(const sf::Event& event);
	void handleHoverEffect(const sf::Event& event);
	void handleResizedWindow(const sf::Event& event);
};

#endif

