//
// Created by benoit on 08/11/2021.
//

#include "Physics.h"
#include "Scenery.h"
#include "Player.h"

void Physics::updatePlayer(Player* player, Scenery* scenery, sf::RenderWindow* window, float dt) {
    float current_x = player->getPosition().x;
    float current_y = player->getPosition().y;

    updateSpeed(player, dt);

    if (player->isMoveLeft()) player->setXPosition(player->getPosition().x - player->getVx() * dt);
    if (player->isMoveRight()) player->setXPosition(player->getPosition().x + player->getVx() * dt);

    if (player->isJmp()) {
        player->setVy(-0.03 * dt);
        player->setJmp(0);
    }

    // WEIGHT
    player->setYPosition(current_y + player->getVy() * dt);

    for (auto platform : scenery->getPlatforms())
        calculateMovement(player, platform, current_x, current_y);

    for (auto target : scenery->getPlayers())
        if (target != player) calculateMovement(player, target, current_x, current_y);

    screenCollision(player, window);

}

void Physics::updateSpeed(Player *p, float dt) {
    float yAcceleration = 0.001;
    p->setVy(p->getVy() + yAcceleration * dt);
}

void Physics::calculateMovement(Player* p, Object* object, float current_x, float current_y) {
    // BOTTOM COLLISION
    if (current_y + p->getSizeY() <= object->getPosition().y && object->getPosition().y <= p->getPosition().y + p->getSizeY())
        if (current_x + p->getSizeX() > object->getPosition().x && current_x < object->getPosition().x + object->getSizeX())
        {
            p->setYPosition(object->getPosition().y - p->getSizeY());
            // RESET SPEED
            p->setVy(0);
        }

    // TOP COLLISION
    if (p->getPosition().y < object->getPosition().y + object->getSizeY() && object->getPosition().y + object->getSizeY() < current_y)
        if (p->getPosition().x + p->getSizeX() > object->getPosition().x && p->getPosition().x < object->getPosition().x + object->getSizeX())
        {
            p->setYPosition(object->getPosition().y + object->getSizeY());
            // RESET SPEED
            p->setVy(0);
        }

    // LEFT COLLISION
    if (current_x + p->getSizeX() <= object->getPosition().x && object->getPosition().x < p->getPosition().x + p->getSizeX())
        if (p->getPosition().y < object->getPosition().y + object->getSizeY() && p->getPosition().y + p->getSizeY() > object->getPosition().y)
        {
            p->setXPosition(object->getPosition().x - p->getSizeX());
            //p->setVx(0);
        }

    // RIGHT COLLISION
    if (p->getPosition().x < object->getPosition().x + object->getSizeX() && object->getPosition().x + object->getSizeX() <= current_x)
        if (p->getPosition().y < object->getPosition().y + object->getSizeY() && p->getPosition().y + p->getSizeY() > object->getPosition().y)
        {
            p->setXPosition(object->getPosition().x + object->getSizeX());
            //p->setVx(0);
        }
}

void Physics::screenCollision(Player *player, sf::RenderWindow *window) {
    if (player->getPosition().x < 0) {
        player->setXPosition(0);
        // player->setVx(0);
    }
    if (player->getPosition().x + player->getSizeX() > window->getSize().x) {
        player->setXPosition(window->getSize().x - player->getSizeX());
        // player->setVx(0);
    }
    if (player->getPosition().y < 0) {
        player->setYPosition(0);
        player->setVy(0);
    }
    if (player->getPosition().y + player->getSizeY() > window->getSize().y) {
        player->setYPosition(window->getSize().y - player->getSizeY());
        player->setVy(0);
    }
}