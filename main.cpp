#include <curses.h>
#include <cstdlib>
#include "src/out_api/init.hpp"
#include "src/out_api/menu_draw.hpp"
#include "src/out_api/game_draw.hpp"

int main() {
    init::begin();
    while (!init::stop()) {
        game_draw::drawAll();
        init::step();
    }
    init::end();    
}
