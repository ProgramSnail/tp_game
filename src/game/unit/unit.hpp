#include <vector>
#include "../game_map.hpp"
#include "../game_events.hpp"
#include "unit_module.hpp"
#include "../map_entities/unit_obj.hpp"

#pragma once

namespace unit {
    class Unit {
    private:
        const size_t MEMORY_SIZE = 100;

        // parts of unit, that do something
        std::vector<Module> modules;
        
        // memory, help modules communicate and handle events
        std::vector<int> memory;

        map::UnitObj unitObj;
        
        map::GameMap* map;

        events::EventCenter* eventCenter;
    public:
        Unit(map::GameMap* map, events::EventCenter* eventCenter);

        void step();

        size_t addModule(Module module);

        void removeModule(size_t id);

        void damage();
    };
}
