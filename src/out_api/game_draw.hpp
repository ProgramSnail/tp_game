#include <bits/c++config.h>
#include <cstdlib>
#include <utility>
#include <vector>
#include <string>
#include "draw.hpp"

#pragma once

namespace game_draw {
    using std::size_t;

    void drawMenuEntity(size_t pos, size_t start, size_t end,
        char shortkey, draw::Cell type,
        const std::string& name, bool isActive);
    
    void drawMenu(std::pair<size_t, size_t> start,
        std::pair<size_t, size_t> end);
    
    void drawMap(std::pair<size_t, size_t> start,
        std::pair<size_t, size_t> end);

    void drawParams(std::pair<size_t, size_t> pos,
        const std::vector<std::pair<int, draw::Cell> >& res);

    void drawRequirements(std::pair<size_t, size_t> pos, 
        const std::vector<draw::Cell>& requirements);

    void drawAll();
}

/*
game scheme:

1234A 1024B 1010011C          | D F S W - resources | unit dependences        
.--------------------------.----------.
|                          |          |
|                          |X Tank   I| - unit: symbol, name, shortkey 
|                          |          |
|                          |          |
|           Map            |   Menu   |
|                          |          |
|                          |          |
|                          .----------.
|                          |103A 104B | - cost
.--------------------------.----------.
                           |MENU_WIDTH| 
*/