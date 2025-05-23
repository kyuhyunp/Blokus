#ifndef MENUSCENE_H 
#define MENUSCENE_H 

#include "Scene.h"


class MenuScene : public Scene {
public:
    MenuScene(sf::RenderWindow& window, Sidebar& sidebar, const ResourceManager& resourceManager);
    void draw() override;
    void update(const sf::Event& event) override;
};

#endif

