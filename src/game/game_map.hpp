#include <vector>
#include "map_entities/cell.hpp"
#include "map_entities/action.hpp"

#pragma once

namespace map {
    class GameMap {
    public:
        using Coord = std::pair<size_t, size_t>;
    private:
        std::vector<std::vector<Cell> > cells;
        std::vector<Action> actions;
        std::vector<size_t> freeActionsId;
    public:
        GameMap(Coord sz);
        
        size_t addAction(const Action& action);

        void removeAction(size_t id);

        const Cell& getCell(Coord pos);

        void setCell(Coord pos, const Cell& cell);

        void setCellBlock(Coord startPos,
                Coord endPos, const Cell& cell);

        void eraseCell(Coord pos);

        void eraseCellBlock(Coord startPos, Coord endPos);

        std::vector<Coord> getWay(
            Coord start,
            Coord end);

        void generate();
    };
}