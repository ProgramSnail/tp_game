#include <vector>
#include "game_events.hpp"
#include "game_map.hpp"
#include "unit/unit.hpp"

#pragma once

class Game {
private:
    size_t playersNum;
    map::GameMap gameMap;
    std::vector<unit::Unit> units;
    events::EventCenter eventCenter;
    // vector<player data>
    // vector<input> // for players
public:
    // may be more than one map sizes ??
    Game(size_t playersNum, std::pair<size_t, size_t> sz);
    void begin();
    void step();
    void end();
};