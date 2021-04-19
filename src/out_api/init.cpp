#include <cstdlib>
#include <unistd.h>
#include <curses.h>
#include "init.hpp"
#include "draw.hpp"
#include "input.hpp"

namespace init {
    WINDOW* stdscr;

    void begin() {
        stdscr = initscr();
        noecho();
        curs_set(false);
        nodelay(stdscr, true);
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