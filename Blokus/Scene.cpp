#include "Scene.h"



Scene::Scene() { 
	resize();
}

unsigned int Scene::getHeight() const {
	return ResourceManager::getWindowPtr()->getSize().y;
}

void Scene::resize() {
	Sidebar::getInstance().resize();
}

void Scene::update(const sf::Event& event) {
	handleWindowClosure(event);
	handleResizedWindow(event);
	handleHoverEffect(event);
}

void Scene::draw() {
	Sidebar::getInstance().draw();	
}

void Scene::draw(const sf::Drawable &drawable) {
	ResourceManager::getWindowPtr()->draw(drawable);
}

void Scene::handleWindowClosure(const sf::Event& event) {
	const auto& windowPtr = ResourceManager::getWindowPtr();
	// Handle Close button
	if (event.is<sf::Event::Closed>()) {
		windowPtr->close();
	}

	// Handle Esc key pressed
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
			windowPtr->close();
		}
	}

	// Handle pressing quit button
	if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (mousePressed->button != sf::Mouse::Button::Left) {
			return;
		}

		const auto mousePos = SFMLUtils::convertToVector2f(mousePressed->position); 
		if (Sidebar::getInstance().isWithinQuitButton(mousePos)) {
			windowPtr->close();
		}
	}
}


void Scene::handleHoverEffect(const sf::Event& event) {
	if (const auto* mouseMoved = event.getIf<sf::Event::MouseMoved>()) {
		const auto mousePos = SFMLUtils::convertToVector2f(mouseMoved->position);

		const auto cursor = Sidebar::getInstance().isWithinQuitButton(mousePos) ?
			sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value() :
			sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();

		ResourceManager::getWindowPtr()->setMouseCursor(cursor);
	}
}

void Scene::handleResizedWindow(const sf::Event& event) {
	if (const auto* resized = event.getIf<sf::Event::Resized>()) {
		resize();

		sf::FloatRect visibleArea(
			{ 0.0f, 0.0f },
			{ static_cast<float>(resized->size.x), static_cast<float>(resized->size.y) }
		);
		ResourceManager::getWindowPtr()->setView(sf::View(visibleArea));
	}
}




