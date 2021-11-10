//
// Created by benoit on 08/11/2021.
//

#include "Physics.h"
#include "Scenery.h"
#include "Player.h"
#include "Math.h"

void Physics::updatePlayer(Player* player, Scenery* scenery, sf::RenderWindow* window, float dt) {
    float current_x = player->getPosition().x;
    float current_y = player->getPosition().y;

    updateSpeed(player, dt);

    if (player->isJmp()) {
        player->setVy(-0.03 * dt);
        player->setJmp(0);
    }


    for (Player* target : scenery->getPlayers())
    {
        if (target != player) {
            //calculateMovement(player, target, current_x, current_y);
            calculatePlayerCollision(player, target);
        }
    }

    player->setXPosition(current_x + player->getVelocity().x * dt);
    player->setYPosition(current_y + player->getVelocity().y * dt);

    for (Platform* platform : scenery->getPlatforms())
        calculateMovement(player, platform, current_x, current_y);



    screenCollision(player, window);
}

void Physics::updateSpeed(Player *player, float dt) {
    float xAcceleration = 0.001;
    float yAcceleration = 0.001;
    float vx = player->getVelocity().x;
    float avx = Math::abs(vx);
    if (player->isMoveLeft()) player->setVx(player->getVelocity().x - xAcceleration * dt);
    if (player->isMoveRight()) player->setVx(player->getVelocity().x + xAcceleration * dt);
    if ((!player->isMoveLeft() && !player->isMoveRight() && avx >= xAcceleration)
    || (player->isMoveRight() && vx < - xAcceleration)
    || (player->isMoveLeft() && vx > xAcceleration))
        if (Math::abs(player->getVelocity().x) >= xAcceleration)
        player->setVx(player->getVelocity().x - Math::sign(player->getVelocity().x) * 2 * xAcceleration * dt);
        else player->setVx(0);
    player->setVy(player->getVelocity().y + yAcceleration * dt);
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
            p->setVx(0);
        }

    // RIGHT COLLISION
    if (p->getPosition().x < object->getPosition().x + object->getSizeX() && object->getPosition().x + object->getSizeX() <= current_x)
        if (p->getPosition().y < object->getPosition().y + object->getSizeY() && p->getPosition().y + p->getSizeY() > object->getPosition().y)
        {
            p->setXPosition(object->getPosition().x + object->getSizeX());
            p->setVx(0);
        }
}

void Physics::screenCollision(Player *player, sf::RenderWindow *window) {
    if (player->getPosition().x < 0) {
        player->setXPosition(0);
        player->setVx(0);
    }
    if (player->getPosition().x + player->getSizeX() > window->getSize().x) {
        player->setXPosition(window->getSize().x - player->getSizeX());
        player->setVx(0);
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

void Physics::calculatePlayerCollision(Player* player, Player* target) {
    if (player->getPosition().x + player->getSizeX() < target->getPosition().x || target->getPosition().x + target->getSizeX() < player->getPosition().x) return;
    if (player->getPosition().y + player->getSizeY() < target->getPosition().y || player->getPosition().y > target->getPosition().y + target->getSizeY()) return;
    float m1 = player->getMass(), m2 = target->getMass();
    float m = m1 + m2;
    sf::Vector2f newV1 = Math::add(Math::mult((m1 - m2) / m, player->getVelocity()), Math::mult(2 * m2 / m, target->getVelocity()));
    sf::Vector2f newV2 = Math::add(Math::mult(2 * m1 / m, player->getVelocity()), Math::mult((m2 - m1) / m, target->getVelocity()));
    player->setVelocity(newV1);
    target->setVelocity(newV2);

}