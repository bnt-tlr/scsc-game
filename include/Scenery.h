//
// Created by benoit on 08/11/2021.
//

#ifndef GAME_SCENERY_H
#define GAME_SCENERY_H

#include <vector>
#include "Player.h"
#include "Platform.h"

class Scenery {

public:
    Scenery();

    const std::vector<Player *> &getPlayers() const;

    void newPlayer(Player* player);

    const std::vector<Platform *> &getPlatforms() const;

    void newPlatform(Platform* platform);

    void update(sf::RenderWindow* window, float dt);

private:
    std::vector<Player*> players;
    std::vector<Platform*> platforms;
};


#endif //GAME_SCENERY_H
