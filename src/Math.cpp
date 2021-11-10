//
// Created by benoit on 10/11/2021.
//

#include "Math.h"
#include <cmath>
#include <cstdio>

sf::Vector2f Math::add(sf::Vector2f vector1, sf::Vector2f vector2) {
    sf::Vector2f result;
    result.x = vector1.x + vector2.x;
    result.y = vector1.y + vector2.y;
    return result;
}

sf::Vector2f Math::mult(float k, sf::Vector2f vector) {
    sf::Vector2f result;
    result.x = k * vector.x;
    result.y = k * vector.y;
    return result;
}

int Math::sign(float k) {
    return k >= 0 ? 1 : -1;
}

float Math::abs(float k) {
    return sign(k) * k;
}