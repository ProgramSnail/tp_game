#include "game_map.hpp"

namespace map {
    GameMap::GameMap(Coord sz) : 
        cells(sz.first, std::vector<Cell>(sz.second)) {}

    size_t GameMap::addAction(const Action& action) {
        if (freeActionsId.size() == 0) {
            actions.push_back(action);
            return actions.size() - 1;
        }
        else {
            size_t id = freeActionsId.back();
            actions[id] = action;
            actions.pop_back();
            return id;
        }
    }

    void GameMap::removeAction(size_t id) {
        actions[id] = Action();
        freeActionsId.push_back(id);
    }

    const Cell& GameMap::getCell(Coord pos) {
        return cells[pos.first][pos.second];
    }

    void GameMap::setCell(Coord pos, const Cell& cell)  {
            cells[pos.first][pos.second] = cell;
    }

    void GameMap::setCellBlock(Coord startPos,
            Coord endPos, const Cell& cell) {
        for (size_t i = startPos.first; i < endPos.first; ++i) { // ?? or <= better ??
            for (size_t j = startPos.second; j < endPos.second; ++j) {
                setCell({i, j}, cell);
            }
        }
    }

    void GameMap::eraseCell(Coord pos) {
        setCell(pos, Cell()); 
    }

    void GameMap::eraseCellBlock(Coord startPos, Coord endPos) {
        setCellBlock(startPos, endPos, Cell());
    }

    std::vector<GameMap::Coord> GameMap::getWay(
        Coord start, Coord end) {
        // now only easiest realisation, then may be A*
        std::vector<Coord> way;
        for (size_t i = start.first; i < end.first;
            start.first < end.first ? ++i : --i) {
            for (size_t j = start.second; i < end.second;
                start.second < end.second ? ++i : --i) {
                way.push_back({i, j});
            }
        }
        return way;
    }

    void GameMap::generate() {
        for (size_t i = 0; cells.size(); ++i) {
            for (size_t j = 0; j < cells[i].size(); ++i) {
                cells[i][j] = Cell();
            } 
        }
    }
}