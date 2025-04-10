#ifndef MENUSCENE_H 
#define MENUSCENE_H 

#include "Scene.h"


class MenuScene : public Scene {
public:
    MenuScene(const sf::Font& font, const std::unique_ptr<sf::RenderWindow>& windowPtr);
    void draw() override;
    void update(const sf::Event& event) override;
};

#endif

