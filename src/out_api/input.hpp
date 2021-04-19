#include <cstdint>
#include <curses.h>

#pragma once

namespace input {
    char lastInput = ERR;

    void begin();

    bool stop();

    void step();

    void end();
}