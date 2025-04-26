#include "MenuScene.h"

MenuScene::MenuScene(sf::RenderWindow& window, FontHolder& fonts)
	: Scene(window, fonts) {}

void MenuScene::draw() {
	Scene::draw();
}

void MenuScene::update(const sf::Event& event) {
	Scene::update(event);
}

