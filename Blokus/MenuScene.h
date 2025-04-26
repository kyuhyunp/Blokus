#ifndef MENUSCENE_H 
#define MENUSCENE_H 

#include "Scene.h"


class MenuScene : public Scene {
public:
    MenuScene(sf::RenderWindow& window, FontHolder& fonts);
    void draw() override;
    void update(const sf::Event& event) override;
};

#endif

