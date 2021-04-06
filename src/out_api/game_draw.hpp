#include <cstdlib>
#include <utility>
#pragma once

namespace game_draw {
    using std::size_t;
    
    void drawAll();
    
    void drawMenu(size_t width, size_t height);
    
    void drawMap(size_t width, size_t height);
}
