#ifndef GAMEENGINE_H 
#define GAMEENGINE_H 

#include <iostream>
#include <memory>
#include "MenuScene.h"
#include "SettingsScene.h"
#include "Sidebar.h"


class GameEngine {
public:
    GameEngine(const ResourceManager& mResourceManager);
    void run();

    // Delete copy constructor and assignment operator
    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;

private:
    // Shared Resources
    const std::unique_ptr<sf::RenderWindow>& mWindowPtr;
    const sf::Font &mFont;
    const ResourceManager& mResourceManager;

    // Member variables
    Sidebar mSidebar;
    std::shared_ptr<Scene> mCurrentScenePtr = nullptr;

    enum class SceneType{
        Menu,
        Settings
    };// TODO: make more types like Game, Settings, End
    std::unordered_map<SceneType, const std::shared_ptr<Scene>> mScenePtrsByType; 

    void render();
};

#endif 
