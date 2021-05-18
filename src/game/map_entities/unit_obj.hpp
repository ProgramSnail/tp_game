#include <utility>
#include <cstdint>
#include "cell.hpp"
#include "../game_map.hpp"

#pragma once

namespace map {
    class UnitObj { // may be useless 
    private:
        using Coord = std::pair<int32_t, int32_t>;
        Coord pos;
        Coord size; 
        GameMap* gameMap;
        Cell cellPrototype;
        

        Coord getEndPos() {
            return {pos.first + size.first,
                pos.second + size.second};
        }
    public:
        UnitObj() = default;
        UnitObj(const Coord& pos, const Coord& size,
                const CellType& cellType, 
                const CellPlayer& cellPlayer, GameMap* gameMap) :
            pos(pos), size(size), gameMap(gameMap),
            cellPrototype(cellType, cellPlayer) {}

        void resize(Coord newSize);

        void move(Coord newPos);

        void setPlayer(int player);

        void setCellType(int cellType);
    };
}