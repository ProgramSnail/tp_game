#pragma once

namespace map {
    enum class CellType {
        ctNone,
        ctUnit,
        ctWeapon,
        ctForest,
        ctMoutain
    };

    enum class CellPlayer {
        cpNone,
        cpPlayer0,
        cpPlayer1,
        cpPlayer2,
        cpPlayer3
    };

    struct Cell {
        CellType type = CellType::ctNone;
        CellPlayer player = CellPlayer::cpNone;
    };
}
