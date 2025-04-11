#include "ResourceManager.h"

ResourceManager::ResourceManager() {
#ifdef _DEBUG
	mWindowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode({ 360, 600 },
		sf::Style::Resize | sf::Style::Close),
		PROJECT_NAME);
#else
	mWindowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode::getFullscreenModes()[0],
		PROJECT_NAME, sf::State::Fullscreen);
#endif

	mWindowPtr->setVerticalSyncEnabled(true);

	if (!mFont.openFromMemory(&helvetica_255_Helvetica_ttf, helvetica_255_Helvetica_ttf_len)) {
		std::cerr << "Error loading font Helvetica\n";
		exit(1);
	}
}

const std::unique_ptr<sf::RenderWindow>& ResourceManager::getWindowPtr() {
	return getInstance().getWindowPtrImpl();
}

const std::unique_ptr<sf::RenderWindow>& ResourceManager::getWindowPtrImpl() {
	return mWindowPtr;
}

const sf::Font& ResourceManager::getFont() {
	return getInstance().getFontImpl();
}

const sf::Font& ResourceManager::getFontImpl() {
	return mFont;
}