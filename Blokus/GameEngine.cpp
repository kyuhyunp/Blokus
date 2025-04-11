#include "GameEngine.h"



GameEngine::GameEngine() {
	const std::shared_ptr<MenuScene> menuScene = std::make_shared<MenuScene>();
	const std::shared_ptr<SettingsScene> settingsScene = std::make_shared<SettingsScene>();

	mScenePtrsByType.insert({ SceneType::Menu, menuScene});
	mScenePtrsByType.insert({ SceneType::Settings, settingsScene });

	mCurrentScenePtr = mScenePtrsByType[SceneType::Menu];
}

void GameEngine::run() {
	// Get the scene
	const std::unique_ptr<sf::RenderWindow>& windowPtr = ResourceManager::getWindowPtr();

	while (windowPtr->isOpen()) {
		while (const std::optional event = windowPtr->pollEvent()) {
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
		
		windowPtr->clear(sf::Color::White);
		mCurrentScenePtr->draw();
		windowPtr->display();
	}
}






