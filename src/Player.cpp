#include "Player.h"

Player::Player(float xPosition, float yPosition) : Player(xPosition, yPosition, 50, 50, sf::Color::Green) {};
Player::Player(float xPosition, float yPosition, float xSize, float ySize, sf::Color color) :
        Object(xPosition, yPosition, xSize, ySize, color) {
    velocity.x = 0;
    velocity.y = 0;
}

void Player::setVx(float vx) {
    Player::velocity.x = vx;
}

void Player::setVy(float vy) {
    Player::velocity.y = vy;
}

sf::Vector2f Player::getVelocity() {
    return velocity;
}

void Player::setVelocity(sf::Vector2f newVelocity) {
    velocity = newVelocity;
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

int Player::getMass() const {
    return mass;
}

void Player::setMass(int mass) {
    Player::mass = mass;
}