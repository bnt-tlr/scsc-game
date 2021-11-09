//
// Created by benoit on 09/11/2021.
//

#ifndef GAME_PLATFORM_H
#define GAME_PLATFORM_H

#include "Object.h"

class Platform: public Object {
public:
    Platform(float xPosition, float yPosition);
    Platform(float xPosition, float yPosition, float xSize, float ySize, sf::Color color);
};

#endif //GAME_PLATFORM_H
