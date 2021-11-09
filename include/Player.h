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

    float getVx() const;
    void setVx(float vx);

    float getVy() const;
    void setVy(float vy);

    bool isMoveLeft() const;
    void setMoveLeft(bool moveLeft);

    bool isMoveRight() const;
    void setMoveRight(bool moveRight);

    bool isJmp() const;
    void setJmp(bool jmp);


private:
    float vx, vy;
    bool move_left = false, move_right = false, jmp = false;

};


#endif //GAME_PLAYER_H
