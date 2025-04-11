#ifndef GAMEENGINE_H 
#define GAMEENGINE_H 

#include <iostream>
#include <memory>
#include "MenuScene.h"
#include "SettingsScene.h"




class GameEngine {
public:
    GameEngine();
    void run();

private:
    std::shared_ptr<Scene> mCurrentScenePtr = nullptr;

    enum class SceneType{
        Menu,
        Settings
    };// TODO: make more types like Game, Settings, End
    std::unordered_map<SceneType, const std::shared_ptr<Scene>> mScenePtrsByType; 

};

#endif 
