#include "Player.h"

Player::Player(float xPosition, float yPosition) : Player(xPosition, yPosition, 50, 50, sf::Color::Green) {};
Player::Player(float xPosition, float yPosition, float xSize, float ySize, sf::Color color) :
        Object(xPosition, yPosition, xSize, ySize, color) {
    Player::vx = 0.5;
    Player::vy = 0;
}

float Player::getVx() const {
    return Player::vx;
}

void Player::setVx(float vx) {
    Player::vx = vx;
}

float Player::getVy() const {
    return Player::vy;
}


void Player::setVy(float vy) {
    Player::vy = vy;
}

bool Player::isMoveLeft() const {
    return move_left;
}

void Player::setMoveLeft(bool moveLeft) {
    move_left = moveLeft;
}

bool Player::isMoveRight() const {
    return move_right;
}

void Player::setMoveRight(bool moveRight) {
    move_right = moveRight;
}

bool Player::isJmp() const {
    return jmp;
}

void Player::setJmp(bool jmp) {
    Player::jmp = jmp;
}