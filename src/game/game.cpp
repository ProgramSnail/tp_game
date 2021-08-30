#include "game.hpp"
#include "game_map.hpp"

Game::Game(size_t playersNum, std::pair<size_t, size_t> sz) :
    playersNum(playersNum), gameMap(sz) {}

void Game::begin() {
    // init map
    // create basic units
}

void Game::step() {
    // gameMap.step();
    for (size_t i = 0; i < units.size(); ++i) {
        units[i].step();
    }
    // all game step
}

void Game::end() {
    // end all 
}