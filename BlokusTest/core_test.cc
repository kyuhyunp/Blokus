#include "pch.h"
#include "../Blokus/ResourceManager.h"
#include <SFML/Graphics.hpp>


namespace core_test {

    class ResourceManagerTest : public testing::Test {
    protected:
        ResourceManager rm_;
    };

    TEST_F(ResourceManagerTest, WindowPtrTest) {
        const std::unique_ptr<sf::RenderWindow>& rm_window_ptr = rm_.getWindowPtr();
        const std::unique_ptr<sf::RenderWindow>& null_unique_ptr = nullptr;

        ASSERT_NE(nullptr, rm_window_ptr);
        ASSERT_NE(null_unique_ptr, rm_window_ptr);
        EXPECT_NO_THROW(rm_window_ptr->clear(sf::Color::Black));
        EXPECT_NO_THROW(rm_window_ptr->display());
    }

    TEST_F(ResourceManagerTest, FontTest) {
        const sf::Font &font = rm_.getFont();
        EXPECT_NO_THROW(sf::Text text(font));
    }
}
    
