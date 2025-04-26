#include "Scene.h"


Scene::Scene(sf::RenderWindow& window, FontHolder& fonts) : 
	mWindow(window), 
	mFonts(fonts)
{}

void Scene::draw() {
}

void Scene::draw(const sf::Drawable& drawable) {
	mWindow.draw(drawable);
}


void Scene::resize() {
}

void Scene::update(const sf::Event& event) {
	handleResizedWindow(event);
	handleHoverEffect(event);
}

unsigned int Scene::getHeight() const {
	return mWindow.getSize().y;
}

void Scene::handleHoverEffect(const sf::Event& event) {
	
}

void Scene::handleResizedWindow(const sf::Event& event) {
	
}




