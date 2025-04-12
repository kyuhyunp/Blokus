#include "MenuScene.h"

MenuScene::MenuScene(Sidebar& sidebar, const ResourceManager& resourceManager)
	: Scene(sidebar, resourceManager) {}

void MenuScene::draw() {
	Scene::draw();
}

void MenuScene::update(const sf::Event& event) {
	Scene::update(event);
}