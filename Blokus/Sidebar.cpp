#include "Sidebar.h"



Sidebar::Sidebar(const ResourceManager& resourceManager)
	: mWindowPtr(resourceManager.getWindowPtr()), mFont(resourceManager.getFont()),
	mResourceManager(resourceManager),
	mBlokusButton(resourceManager.getFont(), BLOKUS_TEXT, TEXT_SIZE),
	mSettingsButton(resourceManager.getFont(), SETTINGS_TEXT, TEXT_SIZE),
	mQuitButton(resourceManager.getFont(), QUIT_TEXT, TEXT_SIZE)
{
	setBlokusButton();
	setSettingsButton();
	setQuitButton();
	updateBorder();
}

bool Sidebar::isWithinQuitButton(const sf::Vector2f& mousePos) const {
	return mQuitButton.getGlobalBounds().contains(mousePos);
}

void Sidebar::resize() {
	updateQuitButtonPosition();
	updateBorder();
}

unsigned int Sidebar::getHeight() const {
	return mWindowPtr->getSize().y;
}

void Sidebar::draw() {
	mWindowPtr->draw(mBorder);
	mWindowPtr->draw(mBlokusButton);
	mWindowPtr->draw(mSettingsButton);
	mWindowPtr->draw(mQuitButton);
}

void Sidebar::setBlokusButton() {
	mBlokusButton.setFillColor(sf::Color::Black);
	mBlokusButton.setStyle(sf::Text::Bold);

	sf::FloatRect dimension = mBlokusButton.getGlobalBounds();
	mBlokusButton.setOrigin({ dimension.size.x / 2.0f, dimension.size.y / 2.0f });
	mBlokusButton.setPosition({ WIDTH / 2.0f, BUTTON_SPACING });
}

void Sidebar::setSettingsButton() {
	mSettingsButton.setFillColor(sf::Color::Black);

	sf::FloatRect dimension = mSettingsButton.getGlobalBounds();
	mSettingsButton.setOrigin({ dimension.size.x / 2.0f, dimension.size.y / 2.0f });
	mSettingsButton.setPosition({ WIDTH / 2.0f, BUTTON_SPACING * 2 });
}

void Sidebar::updateQuitButtonPosition() {
	float height = (BUTTON_SPACING * 3 < getHeight() - BUTTON_SPACING) ? getHeight() - 50.f : 150.f;
	mQuitButton.setPosition({ WIDTH / 2.0f, height});
}

void Sidebar::setQuitButton() {
	mQuitButton.setFillColor(sf::Color::Black);

	sf::FloatRect dimension = mQuitButton.getGlobalBounds();
	mQuitButton.setOrigin({ dimension.size.x / 2.0f, dimension.size.y / 2.0f });
	updateQuitButtonPosition();
}

void Sidebar::updateBorder() {
	mBorder.setSize(sf::Vector2f(static_cast<float>(WIDTH), static_cast<float>(getHeight())));
	mBorder.setPosition({ 0.f, 0.f });
	mBorder.setFillColor(sf::Color(200, 200, 200, 128)); // Transparent gray
}