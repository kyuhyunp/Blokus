#include "Application.h"

namespace Common {
	static const std::string Blokus = "Blokus";
}

Application::Application(const ResourceManager& resourceManager)
	:
#ifdef _DEBUG
mWindow(sf::VideoMode({ 360, 600 }, sf::Style::Resize | sf::Style::Close), Common::Blokus),
#else
mWindow(sf::VideoMode::getFullscreenModes()[0], Common::Blokus, sf::State::Fullscreen),
#endif
mFont(resourceManager.getFont()),
mResourceManager(resourceManager), mSidebar(mWindow, resourceManager), mCurrentScene(SceneType::Menu) {

	const std::shared_ptr<MenuScene> menuScene =
		std::make_shared<MenuScene>(mWindow, mSidebar, mResourceManager);
	const std::shared_ptr<SettingsScene> settingsScene =
		std::make_shared<SettingsScene>(mWindow, mSidebar, mResourceManager);

	mScenePtrsByType.insert({ SceneType::Menu, menuScene });
	mScenePtrsByType.insert({ SceneType::Settings, settingsScene });
}

void Application::run() {
	while (mWindow.isOpen()) {
		while (const std::optional possibleEvent = mWindow.pollEvent()) {
			if (!possibleEvent.has_value()) {
				continue;
			}

			sf::Event event = possibleEvent.value();
			mCurrentScene = getScene(event);
			mScenePtrsByType.at(mCurrentScene)->update(event);
		}

		render();
	}
}

void Application::render()  {
	mWindow.clear(sf::Color::White);
	mScenePtrsByType.at(mCurrentScene)->draw();
	mWindow.display();
}

SceneType Application::getScene(const sf::Event& event) const {
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
		if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
			return SceneType::Settings;
		}
		if (keyPressed->scancode == sf::Keyboard::Scancode::M) {
			return SceneType::Menu;
		}
	}

	return mCurrentScene;
}
