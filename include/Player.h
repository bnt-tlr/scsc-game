//
// Created by benoit on 04/11/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "Object.h"

class Player: public Object {
public:
    Player(float xPosition, float yPosition);
    Player(float xPosition, float yPosition, float xSize, float ySize, sf::Color color);

    void setVx(float vx);
    void setVy(float vy);
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f newVelocity);

    bool isMoveLeft() const;
    void setMoveLeft(bool moveLeft);

    bool isMoveRight() const;
    void setMoveRight(bool moveRight);

    bool isJmp() const;
    void setJmp(bool jmp);

    int getMass()const;
    void setMass(int mass);


private:
    sf::Vector2f velocity;
    float mass;
    bool move_left = false, move_right = false, jmp = false;

};


#endif //GAME_PLAYER_H
