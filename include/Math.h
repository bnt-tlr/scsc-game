//
// Created by benoit on 10/11/2021.
//

#ifndef GAME_MATH_H
#define GAME_MATH_H

#include <SFML/System/Vector2.hpp>


class Math {
public:
    static sf::Vector2f add(sf::Vector2f vector1, sf::Vector2f vector2);
    static sf::Vector2f mult(float k, sf::Vector2f vector);
    static int sign(float k);
    static float abs(float k);
};

#endif //GAME_MATH_H
