#include "GameEngine.h"



GameEngine::GameEngine(const sf::Font &font, const std::unique_ptr<sf::RenderWindow>& windowPtr)
	: mWindowPtr(windowPtr), mFont(font) 
{
	const std::shared_ptr<MenuScene> menuScene = std::make_shared<MenuScene>(font, windowPtr);
	const std::shared_ptr<SettingsScene> settingsScene = std::make_shared<SettingsScene>(font, windowPtr);

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
		
		mWindowPtr->clear(sf::Color::White);
		mCurrentScenePtr->draw();
		mWindowPtr->display();
	}
}






