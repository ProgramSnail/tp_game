#pragma once

namespace map {
    enum class CellType {
        none,
        unit,
        weapon,
        forest,
        moutain
    };

    enum class CellPlayer {
        none,
        player0,
        player1,
        player2,
        player3
    };

    struct Cell {
        CellType type;
        CellPlayer player;
        Cell(CellType type = CellType::none,
                CellPlayer player = CellPlayer::none) 
            : type(type), player(player) {}
    };
}
