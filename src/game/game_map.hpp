#include <vector>
#include "map_entities/cell.hpp"
#include "map_entities/action.hpp"
#include "map_entities/unit_obj.hpp"

#pragma once

namespace map {
    class GameMap {
    private:
        std::vector<std::vector<Cell> > cells;
        std::vector<Action*> actions;
        std::vector<UnitObj> units;
    public:
        GameMap() {

        }
    };
}