#include "Application.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application(FontHolder &fonts)
	:
#ifdef _DEBUG
	mWindow(sf::VideoMode({ 360, 600 }, sf::Style::Resize | sf::Style::Close), Texts::blokus),
#else
	mWindow(sf::VideoMode::getFullscreenModes()[0], Texts::blokus, sf::State::Fullscreen),
#endif
mFonts(fonts),
mSidebar(mWindow, fonts), 
mCurrentScene(SceneType::Menu) {

	std::unique_ptr<MenuScene> menuScene(new MenuScene(mWindow, fonts));
	std::unique_ptr<SettingsScene> settingsScene(new SettingsScene(mWindow, fonts));

	mScenePtrsByType.insert({ SceneType::Menu, std::move(menuScene) });
	mScenePtrsByType.insert({ SceneType::Settings, std::move(settingsScene) });
}

void Application::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) {
		sf::Time timeElapsed = clock.restart();
		timeSinceLastUpdate += timeElapsed;
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
		}
		
		render();
	}
}

void Application::processEvents() {
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


