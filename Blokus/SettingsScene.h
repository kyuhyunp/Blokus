#ifndef SETTINGSSCENE_H 
#define SETTINGSSCENE_H 

#include "Scene.h"

class SettingsScene : public Scene {
public:
    SettingsScene(const sf::Font& font, const std::unique_ptr<sf::RenderWindow>& windowPtr);
    void draw() override;
    void update(const sf::Event& event) override;

    // Game-specific members will go here
    // Settings board

};

#endif

