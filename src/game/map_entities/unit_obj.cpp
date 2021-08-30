#include "unit_obj.hpp"

namespace map {
    void UnitObj::resize(Coord newSize) {
        gameMap->eraseCellBlock(pos, getEndPos());
        size = newSize;
        gameMap->setCellBlock(pos, getEndPos(), cellPrototype);
    }

    void UnitObj::move(Coord newPos) {
        gameMap->eraseCellBlock(pos, getEndPos());
        pos = newPos;
        gameMap->setCellBlock(pos, getEndPos(), cellPrototype);
    }

    void UnitObj::setPlayer(int player) {
        cellPrototype.player = static_cast<CellPlayer>(player);
    }

    void UnitObj::setCellType(int cellType) {
        cellPrototype.type = static_cast<CellType>(cellType);
    }
}