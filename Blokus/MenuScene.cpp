#include "MenuScene.h"

MenuScene::MenuScene(const sf::Font& font, const std::unique_ptr<sf::RenderWindow>& windowPtr) 
	: Scene(font, windowPtr) {}

void MenuScene::draw() {
	Scene::draw();
}

void MenuScene::update(const sf::Event& event) {
	Scene::update(event);
}