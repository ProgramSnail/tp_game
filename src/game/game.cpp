#include "game.hpp"
#include "game_map.hpp"

Game::Game(size_t playersNum, std::pair<size_t, size_t> sz) :
    playersNum(playersNum), gameMap(sz) {}