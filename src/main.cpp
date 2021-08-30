#include <curses.h>
#include <cstdlib>
#include "game/game.hpp"
#include "out_api/init.hpp"
#include "out_api/menu_draw.hpp"
#include "out_api/game_draw.hpp"

int main() {
    Game game(2, {100, 100});
    game.begin();
    init::begin();
    while (!init::stop()) {
        game_draw::drawAll();
        game.step();
        init::step();
    }
    init::end();
    game.end();    
}
