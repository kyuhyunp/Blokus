#include "pch.h"
#include "../Blokus/ResourceManager.h"
#include <memory>
#include <SFML/Graphics.hpp>

namespace core_test {
    TEST(ResourceManagerTest, WindowPtrTest) {
        ResourceManager rm;
        const std::unique_ptr<sf::RenderWindow>& rm_window_ptr = rm.getWindowPtr();
        const std::unique_ptr<sf::RenderWindow>& null_ptr = nullptr;

        ASSERT_NE(nullptr, rm_window_ptr);
        ASSERT_NE(null_ptr, rm_window_ptr);
        EXPECT_NO_THROW(rm_window_ptr->clear(sf::Color::Black));
        EXPECT_NO_THROW(rm_window_ptr->display());
    }

    TEST(ResourceManagerTest, FontTest) {
        ResourceManager rm;
        const sf::Font &font = rm.getFont();

        EXPECT_NO_THROW(sf::Text text(font));
    }

    
    

}
    
