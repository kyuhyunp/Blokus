#include "Sidebar.h"


Sidebar::Sidebar(sf::RenderWindow& window, FontHolder& fonts) : 
	mWindow(window), 
	mFonts(fonts),
	mBlokusButton(fonts.get(Fonts::Helvetica), BLOKUS_TEXT, TEXT_SIZE),
	mSettingsButton(fonts.get(Fonts::Helvetica), SETTINGS_TEXT, TEXT_SIZE),
	mQuitButton(fonts.get(Fonts::Helvetica), QUIT_TEXT, TEXT_SIZE)
{
	setBlokusButton();
	setSettingsButton();
	setQuitButton();
	setBorder();
}

void Sidebar::resize() {
	updateQuitButtonPosition();
	updateBorder();
}

void Sidebar::draw() {
	mWindow.draw(mBorder);
	mWindow.draw(mBlokusButton);
	mWindow.draw(mSettingsButton);
	mWindow.draw(mQuitButton);
}

void Sidebar::update(const sf::Event& event) {
	// Handle button touch
	if (const auto* mouseMoved = event.getIf<sf::Event::MouseMoved>()) {
		const auto mousePos = SFMLUtils::convertToVector2f(mouseMoved->position);

		const auto cursor = isWithinQuitButton(mousePos) ?
			sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value() :
			sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();

		mWindow.setMouseCursor(cursor);
	}

	// Handle button press
	if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (mousePressed->button != sf::Mouse::Button::Left) {
			return;
		}

		const auto mousePos = SFMLUtils::convertToVector2f(mousePressed->position);
		if (isWithinQuitButton(mousePos)) {
			mWindow.close();
		}
	}
}

bool Sidebar::isWithinQuitButton(const sf::Vector2f& mousePos) const {
	return mQuitButton.getGlobalBounds().contains(mousePos);
}

const sf::FloatRect Sidebar::getQuitButtonBoundary() const {
	return mQuitButton.getGlobalBounds();
}

const unsigned int Sidebar::getWidth() const {
	return WIDTH;
}

const float Sidebar::getButtonSpacing() const {
	return BUTTON_SPACING;
}


unsigned int Sidebar::getHeight() const {
	return mWindow.getSize().y;
}

void Sidebar::setBlokusButton() {
	mBlokusButton.setFillColor(sf::Color::Black);
	mBlokusButton.setStyle(sf::Text::Bold);

	sf::FloatRect dimension = mBlokusButton.getLocalBounds();
	mBlokusButton.setOrigin({ dimension.size.x / 2.0f, dimension.size.y / 2.0f });
	mBlokusButton.setPosition({ WIDTH / 2.0f, BUTTON_SPACING });
}

void Sidebar::setSettingsButton() {
	mSettingsButton.setFillColor(sf::Color::Black);

	sf::FloatRect dimension = mSettingsButton.getLocalBounds();
	mSettingsButton.setOrigin({ dimension.size.x / 2.0f, dimension.size.y / 2.0f });
	mSettingsButton.setPosition({ WIDTH / 2.0f, getButtonSpacing() * 2 });
}

void Sidebar::updateQuitButtonPosition() {
	float height = (getButtonSpacing() * 3 < getHeight() - getButtonSpacing()) ? getHeight() - getButtonSpacing() : getButtonSpacing() * 3;
	mQuitButton.setPosition({ WIDTH / 2.0f, height});
}

void Sidebar::setQuitButton() {
	mQuitButton.setFillColor(sf::Color::Black);

	sf::FloatRect dimension = mQuitButton.getLocalBounds();
	mQuitButton.setOrigin({ dimension.size.x / 2.0f, dimension.size.y / 2.0f });
	updateQuitButtonPosition();
}

void Sidebar::setBorder() {
	mBorder.setSize(sf::Vector2f(static_cast<float>(WIDTH), static_cast<float>(getHeight())));
	mBorder.setPosition({ 0.f, 0.f });
	mBorder.setFillColor(sf::Color(200, 200, 200, 128)); // Transparent gray
}

void Sidebar::updateBorder() {
	mBorder.setSize(sf::Vector2f(static_cast<float>(WIDTH), static_cast<float>(getHeight())));
}