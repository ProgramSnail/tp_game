#include <utility>
#include <cstdint>
#include "cell.hpp"

#pragma once

namespace map {
    class UnitObj { // may be useless 
    private:
        using Coord = std::pair<int32_t, int32_t>;
        Coord pos;
        Coord size;
        CellType cellType;      
    public:
        UnitObj(const Coord& pos, const Coord& size, const CellType& cellType) :
            pos(pos), size(size), cellType(cellType) {

        }
        void updateAll() {

        }
    };
}