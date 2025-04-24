#include "Scene.h"



Scene::Scene(sf::RenderWindow& window, Sidebar& sidebar, const ResourceManager& resourceManager)
	: mWindow(window), mFont(resourceManager.getFont()),
	mResourceManager(resourceManager),
	mSidebar(sidebar)
{
	resize();
}

unsigned int Scene::getHeight() const {
	return mWindow.getSize().y;
}

void Scene::resize() {
	mSidebar.resize();
}

void Scene::update(const sf::Event& event) {
	handleWindowClosure(event);
	handleResizedWindow(event);
	handleHoverEffect(event);
}

void Scene::draw() {
	mSidebar.draw();	
}

void Scene::draw(const sf::Drawable &drawable) {
	mWindow.draw(drawable);
}

void Scene::handleWindowClosure(const sf::Event& event) {
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

	// Handle pressing quit button
	if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (mousePressed->button != sf::Mouse::Button::Left) {
			return;
		}

		const auto mousePos = SFMLUtils::convertToVector2f(mousePressed->position); 
		if (mSidebar.isWithinQuitButton(mousePos)) {
			mWindow.close();
		}
	}
}


void Scene::handleHoverEffect(const sf::Event& event) {
	if (const auto* mouseMoved = event.getIf<sf::Event::MouseMoved>()) {
		const auto mousePos = SFMLUtils::convertToVector2f(mouseMoved->position);

		const auto cursor = mSidebar.isWithinQuitButton(mousePos) ?
			sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value() :
			sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();

		mWindow.setMouseCursor(cursor);
	}
}

void Scene::handleResizedWindow(const sf::Event& event) {
	if (const auto* resized = event.getIf<sf::Event::Resized>()) {
		resize();

		sf::FloatRect visibleArea(
			{ 0.0f, 0.0f },
			{ static_cast<float>(resized->size.x), static_cast<float>(resized->size.y) }
		);
		mWindow.setView(sf::View(visibleArea));
	}
}




