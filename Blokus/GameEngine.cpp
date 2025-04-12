#include "GameEngine.h"



GameEngine::GameEngine(const ResourceManager& resourceManager) 
: mWindowPtr(resourceManager.getWindowPtr()), mFont(resourceManager.getFont()),
mResourceManager(resourceManager), mSidebar(resourceManager){
	const std::shared_ptr<MenuScene> menuScene = 
		std::make_shared<MenuScene>(mSidebar, mResourceManager);
	const std::shared_ptr<SettingsScene> settingsScene = 
		std::make_shared<SettingsScene>(mSidebar, mResourceManager);

	mScenePtrsByType.insert({ SceneType::Menu, menuScene});
	mScenePtrsByType.insert({ SceneType::Settings, settingsScene });

	mCurrentScenePtr = mScenePtrsByType[SceneType::Menu];
}

void GameEngine::run() {
	// Get the scene
	while (mWindowPtr->isOpen()) {
		while (const std::optional event = mWindowPtr->pollEvent()) {
			if (!event.has_value()) {
				continue;
			}

			// TODO: handle scene switch using a method
			if (const auto* keyPressed = event.value().getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
					mCurrentScenePtr = mScenePtrsByType[SceneType::Settings];
				}
			}
			if (const auto* keyPressed = event.value().getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::M) {
					mCurrentScenePtr = mScenePtrsByType[SceneType::Menu];
				}
			}

			mCurrentScenePtr->update(event.value());
		}
		
		render();
	}
}

void GameEngine::render() {
	mWindowPtr->clear(sf::Color::White);
	mCurrentScenePtr->draw();
	mWindowPtr->display();
}






