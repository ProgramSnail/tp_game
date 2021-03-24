#include <vector>
#include "../game_map.hpp"
#include "unit_module.hpp"
#include "unit_memory_elem.hpp"

#pragma once

namespace unit {
    class Unit {
    private:
        std::vector<Module> modules;
        std::vector<MemoryElem> memory;
        map::GameMap map;
    public:
        Unit();

        void update();
    };
}