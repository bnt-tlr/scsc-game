//
// Created by benoit on 08/11/2021.
//

#ifndef GAME_PHYSICS_H
#define GAME_PHYSICS_H

#include "Scenery.h"
#include "Player.h"

class Physics {

public:
    static void updatePlayer(Player* player, Scenery* scenery, sf::RenderWindow* window, float dt);

private:
    static void updateSpeed(Player* player, float dt);
    static void calculateMovement(Player* player, Object* object, float currentX, float currentY);
    static void screenCollision(Player* player, sf::RenderWindow* window);
};


#endif //GAME_PHYSICS_H
