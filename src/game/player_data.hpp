#pragma once

struct PlayerData { // may be class better
    static int maxPlayerId;
    int player;
    int resources = 0;

    PlayerData() {
        player = maxPlayerId;
        ++maxPlayerId;
    }
};