#include "MenuScene.h"

MenuScene::MenuScene(sf::RenderWindow& window, Sidebar& sidebar, const ResourceManager& resourceManager)
	: Scene(window, sidebar, resourceManager) {}

void MenuScene::draw() {
	Scene::draw();
}

void MenuScene::update(const sf::Event& event) {
	Scene::update(event);
}