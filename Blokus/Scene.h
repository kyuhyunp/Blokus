#ifndef SCENE_H 
#define SCENE_H 

#include "Sidebar.h"
#include "SFMLUtils.h"


class Scene {
public:
	Scene();
	virtual void update(const sf::Event& event);
	virtual void draw();
	void draw(const sf::Drawable& drawable);
	

private:

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

