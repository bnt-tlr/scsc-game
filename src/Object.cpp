//
// Created by benoit on 08/11/2021.
//

#include "Object.h"

Object::Object(float x, float y, float sizeX, float sizeY, sf::Color color) {
    Object::setXPosition(x);
    Object::setYPosition(y);
    Object::shape = new sf::RectangleShape(sf::Vector2<float>(sizeX, sizeY));
    Object::shape->setFillColor(color);
}

sf::Vector2f Object::getPosition() {
    return position;
}

void Object::setXPosition(float x) {
    position.x = x;
}

void Object::setYPosition(float y) {
    position.y = y;
}

float Object::getSizeX() const {
    return shape->getSize().x;
}

float Object::getSizeY() const {
    return shape->getSize().y;
}

void Object::update() {
    Object::shape->setPosition(position.x, position.y);
}

void Object::draw(sf::RenderWindow* window) {
    window->draw(*Object::shape);
}