#ifndef APPLICATION_H 
#define APPLICATION_H 

#include <iostream>
#include <memory>
#include "MenuScene.h"
#include "SettingsScene.h"
#include "Sidebar.h"
#include "ResourceIdentifiers.h"
#include "ResourceHolder.h"
#include "Common.h"

class Application {

public:
    Application(FontHolder &fonts);
    void run();

    // Delete copy constructor and assignment operator
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

private:
    static const sf::Time TimePerFrame;

    // Shared Resources
    sf::RenderWindow mWindow;
    FontHolder &mFonts;

    // Member variables
    Sidebar mSidebar;
    SceneType mCurrentScene;
    std::unordered_map<SceneType, std::unique_ptr<Scene>> mScenePtrsByType;

    void processEvents();
    void render();
    SceneType getScene(const sf::Event& event) const;

    void handleResizedWindow(const sf::Event& event);
    void handleWindowClosure(const sf::Event& event);
};

#endif 


