//
// Created by benoit on 09/11/2021.
//

#include "Platform.h"

Platform::Platform(float x, float y): Platform(x, y, 500, 25, sf::Color::White) {};
Platform::Platform(float x, float y, float sizeX, float sizeY, sf::Color color) :
        Object(x, y, sizeX, sizeY, color) {}