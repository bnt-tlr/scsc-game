//
// Created by benoit on 08/11/2021.
//

#include "Scenery.h"
#include "Physics.h"

Scenery::Scenery() {}

const std::vector<Player *> &Scenery::getPlayers() const {
    return players;
}

void Scenery::newPlayer(Player* newPlayer) {
    Scenery::players.push_back(newPlayer);
}

const std::vector<Platform *> &Scenery::getPlatforms() const {
    return platforms;
}

void Scenery::newPlatform(Platform* newPlatform) {
    Scenery::platforms.push_back(newPlatform);
}

void Scenery::update(sf::RenderWindow* window, float dt) {
    for (Platform* platform : platforms) {
        platform->update();
        platform->draw(window);
    }

    for (Player* p : players) {
        Physics::updatePlayer(p, this, window, dt);
        p->update();
        p->draw(window);
    }
}