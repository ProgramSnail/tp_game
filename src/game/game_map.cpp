#include "game_map.hpp"

namespace map {
    GameMap::GameMap(std::pair<size_t, size_t> sz) : 
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
        actions[id] = Action(); // empty action;
        freeActionsId.push_back(id);
    }

    const Cell& GameMap::getCell(std::pair<size_t, size_t> pos) {
        return cells[pos.first][pos.second];
    }

    void GameMap::setCell(std::pair<size_t, size_t> pos,
        const Cell& cell)  {
            cells[pos.first][pos.second] = cell;
    }

    std::vector<std::pair<size_t, size_t>> GameMap::getWay(
        std::pair<size_t, size_t> start,
        std::pair<size_t, size_t> end) {
        // now only easiest realisation, then may be A*
        std::vector<std::pair<size_t, size_t>> way;
        for (size_t i = start.first; i < end.first;
            start.first < end.first ? ++i : --i) {
            for (size_t j = start.second; i < end.second;
                start.second < end.second ? ++i : --i) {
                way.push_back({i, j});
            }
        }
        return way;
    }
}