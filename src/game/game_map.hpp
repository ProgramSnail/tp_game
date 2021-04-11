#include <vector>
#include "map_entities/cell.hpp"
#include "map_entities/action.hpp"

#pragma once

namespace map {
    class GameMap {
    private:
        std::vector<std::vector<Cell> > cells;
        std::vector<Action> actions;
        std::vector<size_t> freeActionsId;
    public:
        GameMap(std::pair<size_t, size_t> sz);
        
        size_t addAction(const Action& action);

        void removeAction(size_t id);

        const Cell& getCell(std::pair<size_t, size_t> pos);

        void setCell(std::pair<size_t, size_t> pos,
            const Cell& cell);

        std::vector<std::pair<size_t, size_t>> getWay(
            std::pair<size_t, size_t> start,
            std::pair<size_t, size_t> end);

    };
}