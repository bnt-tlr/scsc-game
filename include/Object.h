//
// Created by benoit on 08/11/2021.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Object {
public:
    Object(float xPosition, float yPosition, float xSize, float ySize, sf::Color color);

    sf::Vector2f getPosition();
    void setXPosition(float x);
    void setYPosition(float y);

    float getSizeX() const;
    float getSizeY() const;

    void update();
    void draw(sf::RenderWindow* window);

protected:
    sf::Vector2f position;
    sf::RectangleShape* shape;
};


#endif //GAME_OBJECT_H
