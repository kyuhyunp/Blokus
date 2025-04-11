#include "SettingsScene.h"



SettingsScene::SettingsScene()
	: Scene() {
}


void SettingsScene::draw() {
	Scene::draw();
	sf::RectangleShape rec({ 300.f, 200.f });
	rec.setFillColor(sf::Color::Black);
	Scene::draw(rec);
}

void SettingsScene::update(const sf::Event& event) {
	Scene::update(event);
}
