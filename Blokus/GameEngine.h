#ifndef GAMEENGINE_H 
#define GAMEENGINE_H 

#include <iostream>
#include <memory>
#include "Scene.h"
#include "MenuScene.h"
#include "SettingsScene.h"

/*
* Should be able to add Sidebar, Board, Pieces
* 
*/
class GameEngine {
public:
    GameEngine(const sf::Font &font, const std::unique_ptr<sf::RenderWindow>& windowPtr);
    void run();

private:
    const sf::Font& mFont;
    const std::unique_ptr<sf::RenderWindow>& mWindowPtr;
    std::shared_ptr<Scene> mCurrentScenePtr = nullptr;

    enum class SceneType{
        Menu,
        Settings
    };// TODO: make more types like Game, Settings, End
    std::unordered_map<SceneType, const std::shared_ptr<Scene>> mScenePtrsByType; 

};

#endif 
