#pragma once

namespace map {
    enum class CellType { // needed to choose final types
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
        CellType type;
        // int ??speed??; // speed when move inside
    };
}
