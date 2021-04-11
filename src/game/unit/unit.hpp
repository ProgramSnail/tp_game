#include <vector>
#include "../game_map.hpp"
#include "unit_module.hpp"

#pragma once

namespace unit {
    class Unit {
    private:
        // parts of unit, that do something
        std::vector<Module> modules;
        
        // memory, help modules communicate and handle events
        std::vector<int> memory;
        
        map::GameMap* map;
    public:
        Unit();

        void update();
    };
}
