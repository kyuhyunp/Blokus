#include "Application.h"

namespace Common {
	static const std::string Blokus = "Blokus";
}

Application::Application(FontHolder &fonts)
	:
#ifdef _DEBUG
	mWindow(sf::VideoMode({ 360, 600 }, sf::Style::Resize | sf::Style::Close), Common::Blokus),
#else
	mWindow(sf::VideoMode::getFullscreenModes()[0], Common::Blokus, sf::State::Fullscreen),
#endif
mFonts(fonts),
mSidebar(mWindow, fonts), 
mCurrentScene(SceneType::Menu) {

	const std::shared_ptr<MenuScene> menuScene =
		std::make_shared<MenuScene>(mWindow, fonts);
	const std::shared_ptr<SettingsScene> settingsScene =
		std::make_shared<SettingsScene>(mWindow, fonts);

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
			handleWindowClosure(event);
			handleResizedWindow(event);

			mSidebar.update(event);
			mCurrentScene = getScene(event);
			mScenePtrsByType.at(mCurrentScene)->update(event);
		}

		render();
	}
}

void Application::render()  {
	mWindow.clear(sf::Color::White);
	mSidebar.draw();
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

void Application::handleWindowClosure(const sf::Event& event) {
	// Handle Close button
	if (event.is<sf::Event::Closed>()) {
		mWindow.close();
	}

	// Handle Esc key pressed
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
			mWindow.close();
		}
	}
}

void Application::handleResizedWindow(const sf::Event& event) {
	if (const auto* resized = event.getIf<sf::Event::Resized>()) {
		mSidebar.resize();
		mScenePtrsByType.at(mCurrentScene)->resize();

		sf::FloatRect visibleArea(
			{ 0.0f, 0.0f },
			{ static_cast<float>(resized->size.x), static_cast<float>(resized->size.y) }
		);
		mWindow.setView(sf::View(visibleArea));
	}
}


