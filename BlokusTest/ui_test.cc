#include "pch.h"
#include "resource_allocation.cc"
#include "../Blokus/Sidebar.h"
#include "../Blokus/SFMLUtils.h"

#include <memory>
#include <SFML/Graphics.hpp>

namespace ui_test {

	TEST(SidebarTest, getQuitButtonBoundaryTest) {
		auto window = sf::RenderWindow(
			sf::VideoMode({ 1920, 1080 }, sf::Style::Resize | sf::Style::Close), "Test");
		FontHolder fonts;
		Resource::loadResources(fonts);

		Sidebar sb(window, fonts);
		sf::FloatRect boundary = sb.getQuitButtonBoundary();

		sf::Vector2f middle = { sb.getWidth() / 2.f, window.getSize().y - sb.getButtonSpacing() };
		EXPECT_TRUE(boundary.contains(middle));
	}

	TEST(SidebarTest, IsWithinQuitButtonTest) {
		auto window = sf::RenderWindow(
			sf::VideoMode({ 1920, 1080 }, sf::Style::Resize | sf::Style::Close), "Test");
		FontHolder fonts;
		Resource::loadResources(fonts);

		Sidebar sb1(window, fonts);
		sf::FloatRect fullScreenBoundary = sb1.getQuitButtonBoundary();
		EXPECT_TRUE(sb1.isWithinQuitButton(fullScreenBoundary.getCenter()));
		EXPECT_TRUE(sb1.isWithinQuitButton(fullScreenBoundary.position));
		EXPECT_FALSE(sb1.isWithinQuitButton(fullScreenBoundary.position + fullScreenBoundary.size));


		auto smallWindow = sf::RenderWindow(
			sf::VideoMode({ 360, 600 }, sf::Style::Resize | sf::Style::Close), "Test");
		
		Sidebar sb2(smallWindow, fonts);
		sf::FloatRect boundary = sb2.getQuitButtonBoundary();
		EXPECT_NE(boundary, fullScreenBoundary);
		EXPECT_TRUE(sb2.isWithinQuitButton(boundary.getCenter()));
		EXPECT_TRUE(sb2.isWithinQuitButton(boundary.position));
		EXPECT_FALSE(sb2.isWithinQuitButton(boundary.position + boundary.size));
	}

	class SidebarMock: public Sidebar {
	public:
		SidebarMock(sf::RenderWindow& window, FontHolder& fonts) :
			Sidebar(window, fonts) { }
		MOCK_METHOD(bool, isWithinQuitButton, (const sf::Vector2f& mousePos), (override, const));
		
	};

	// Use Mock to test if resized
	TEST(SidebarTest, cursorUpdateTest) {
		auto window = sf::RenderWindow(
			sf::VideoMode({ 400, 400 }, sf::Style::Resize | sf::Style::Close), "Test");
		FontHolder fonts;
		Resource::loadResources(fonts);

		SidebarMock sb_mock(window, fonts);
		sf::FloatRect boundary = sb_mock.getQuitButtonBoundary();

		{ // Within the button
			sf::Vector2i middlePos = static_cast<sf::Vector2i> (boundary.getCenter());
			sf::Event::MouseMoved withinButton = { middlePos };
			EXPECT_CALL(sb_mock, isWithinQuitButton(SFMLUtils::convertToVector2f(middlePos)))
				.Times(1);

			EXPECT_NO_THROW(sb_mock.update(withinButton));
		}

		{ // Don't expect a cursor change
			sf::Vector2i cornerPos = static_cast<sf::Vector2i> (boundary.position + boundary.size);
			sf::Event::MouseMoved outButton = { cornerPos };
			EXPECT_CALL(sb_mock, isWithinQuitButton(SFMLUtils::convertToVector2f(cornerPos)))
				.Times(1);

			EXPECT_NO_THROW(sb_mock.update(outButton));
		}
	}

}

