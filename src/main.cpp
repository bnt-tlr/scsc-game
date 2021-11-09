//
// Created by benoit on 04/11/2021.
//
#include <SFML/Window/Event.hpp>
#include "Player.h"
#include "Scenery.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Game");
    Scenery scenery = Scenery();

    scenery.newPlayer(new Player(25, 650));
    scenery.newPlatform(new Platform(0, 700, 1000, 25, sf::Color::White));
    scenery.newPlatform(new Platform(500, 600, 200, 25, sf::Color::Blue));
    scenery.newPlatform(new Platform(750, 500, 200, 25, sf::Color::Red));
    scenery.newPlatform(new Platform(100, 500, 200, 25, sf::Color::Cyan));
    scenery.newPlatform(new Platform(25, 400, 100, 25, sf::Color::Yellow));
    scenery.newPlatform(new Platform(300, 325, 50, 25, sf::Color::Blue));
    scenery.newPlatform(new Platform(600, 250, 200, 25, sf::Color::Magenta));
    scenery.newPlatform(new Platform(350, 450, 25, 75, sf::Color::Red));

    sf::Clock fpsClk;
    const int FPS = 60;
    const float dt = 1000 / FPS;

    while (window.isOpen()) {
        while (fpsClk.getElapsedTime().asMilliseconds() < 1000 / FPS) {}

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code) {
                case sf::Keyboard::Q:
                    scenery.getPlayers()[0]->setMoveLeft(1);
                        break;
                case sf::Keyboard::D:
                    scenery.getPlayers()[0]->setMoveRight(1);
                    break;
                case sf::Keyboard::Z:
                    // DISALLOW JUMP IF FALLING (EXCEPT FOR SMALL VY)
                    if (scenery.getPlayers()[0]->getVy() >= -0.1 && scenery.getPlayers()[0]->getVy() <= 0.1)
                        scenery.getPlayers()[0]->setJmp(1);
                    break;
                }

            if (event.type == sf::Event::KeyReleased)
                switch (event.key.code) {
                    case sf::Keyboard::Q:
                        scenery.getPlayers()[0]->setMoveLeft(0);
                        break;
                    case sf::Keyboard::D:
                        scenery.getPlayers()[0]->setMoveRight(0);
                        break;
                }

        }

        window.clear();
        scenery.update(&window, dt);
        window.display();
        fpsClk.restart();
    }

}