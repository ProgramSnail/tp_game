#include <cstdlib>
#include <unistd.h>
#include <curses.h>
#include "init.hpp"
#include "draw.hpp"
#include "input.hpp"

namespace init {
    void begin() {
        initscr();
        noecho();
        curs_set(false);
        draw::begin();
        input::begin();
    }

    bool stop() {
        return input::stop();
    }

    void step() {
        draw::step();
        usleep(STEP_DELAY_USEC);
    }

    void end() {
        draw::end();
        input::end();
        endwin();
    }
}