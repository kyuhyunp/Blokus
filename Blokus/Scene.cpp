#include "Scene.h"



Scene::Scene(const sf::Font& font, const std::unique_ptr<sf::RenderWindow>& windowPtr)
	: mFont(font), mWindowPtr(windowPtr)
{ 
	resize();
}

unsigned int Scene::getHeight() const {
	return mWindowPtr->getSize().y;
}

void Scene::resize() {
	Sidebar::getInstance(mFont, mWindowPtr).resize();
}

void Scene::update(const sf::Event& event) {
	handleWindowClosure(event);
	handleResizedWindow(event);
	handleHoverEffect(event);
}

void Scene::draw() {
	Sidebar::getInstance(mFont, mWindowPtr).draw();	
}

void Scene::draw(const sf::Drawable &drawable) {
	mWindowPtr->draw(drawable);
}

void Scene::handleWindowClosure(const sf::Event& event) {
	// Handle Close button
	if (event.is<sf::Event::Closed>()) {
		mWindowPtr->close();
	}

	// Handle Esc key pressed
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
			mWindowPtr->close();
		}
	}

	// Handle pressing quit button
	if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (mousePressed->button != sf::Mouse::Button::Left) {
			return;
		}

		const auto mousePos = SFMLUtils::convertToVector2f(mousePressed->position); 
		if (Sidebar::getInstance(mFont, mWindowPtr).isWithinQuitButton(mousePos)) {
			mWindowPtr->close();
		}
	}
}


void Scene::handleHoverEffect(const sf::Event& event) {
	if (const auto* mouseMoved = event.getIf<sf::Event::MouseMoved>()) {
		const auto mousePos = SFMLUtils::convertToVector2f(mouseMoved->position);

		const auto cursor = Sidebar::getInstance(mFont, mWindowPtr).isWithinQuitButton(mousePos) ?
			sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value() :
			sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();

		mWindowPtr->setMouseCursor(cursor);
	}
}

void Scene::handleResizedWindow(const sf::Event& event) {
	if (const auto* resized = event.getIf<sf::Event::Resized>()) {
		resize();

		sf::FloatRect visibleArea(
			{ 0.0f, 0.0f },
			{ static_cast<float>(resized->size.x), static_cast<float>(resized->size.y) }
		);
		mWindowPtr->setView(sf::View(visibleArea));
	}
}




