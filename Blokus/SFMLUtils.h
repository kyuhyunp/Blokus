#ifndef SFMLUTILS_H
#define SFMLUTILS_H

#include <SFML/Graphics.hpp>

namespace SFMLUtils {
    /// @brief Converts an SFML integer vector to a float vector
    /// @param pos The integer vector to convert
    /// @return The converted float vector
    inline sf::Vector2f convertToVector2f(const sf::Vector2i& pos) {
        return sf::Vector2f{
            static_cast<float>(pos.x),
            static_cast<float>(pos.y)
        };
    }
}

#endif 
