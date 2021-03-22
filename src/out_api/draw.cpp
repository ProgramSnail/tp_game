#include "draw.hpp"
#include <cstdlib>
#include <unistd.h>
#include <curses.h>

namespace draw {

    enum Color {
        black = 0,
        red = 1,
        green = 2,
        yellow = 3,
        blue = 4,
        magneta = 5,
        cyan = 6,
        white = 7,
    };

    void initColorPairs() {
        init_pair(ColorScheme::simple, COLOR_BLACK, COLOR_WHITE);
        init_pair(ColorScheme::active, COLOR_WHITE, COLOR_BLACK);
        init_pair(ColorScheme::player0, COLOR_BLACK, COLOR_RED);
        init_pair(ColorScheme::player1, COLOR_BLACK, COLOR_BLUE);
        init_pair(ColorScheme::player2, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(ColorScheme::player3, COLOR_BLACK, COLOR_YELLOW);
        init_pair(ColorScheme::neutral, COLOR_WHITE, COLOR_GREEN);
        init_pair(ColorScheme::enviroment, COLOR_BLACK, COLOR_WHITE);
    }

    void begin() {
        initscr();
        noecho();
        curs_set(false);
        start_color();
        initColorPairs();
    }

    void step() {
        refresh();
        usleep(STEP_DELAY_USEC);
    }

    void end() {
        endwin();
    }

    void clearAll() {
        clear();
    }

    void drawCh(uint32_t x, uint32_t y,
        Cell cell, ColorScheme colorScheme) {
        attron(COLOR_PAIR(colorScheme));
        mvaddch(y, x, cell);
        attroff(COLOR_PAIR(colorScheme));
    }

    void getSize(uint32_t& x, uint32_t& y) {
        getmaxyx(stdscr, y, x);
    }
}