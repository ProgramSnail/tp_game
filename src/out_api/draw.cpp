#include <cstdlib>
#include <curses.h>
#include "draw.hpp"

namespace draw {
    void initColorPairs() {
        init_pair(ColorScheme::blank, COLOR_BLACK, COLOR_WHITE);
        init_pair(ColorScheme::map_simple, COLOR_BLACK, COLOR_WHITE);
        init_pair(ColorScheme::map_active, COLOR_WHITE, COLOR_BLACK);
        init_pair(ColorScheme::menu_simple, COLOR_BLACK, COLOR_WHITE);
        init_pair(ColorScheme::menu_active, COLOR_WHITE, COLOR_BLACK);
        init_pair(ColorScheme::player0, COLOR_BLACK, COLOR_RED);
        init_pair(ColorScheme::player1, COLOR_BLACK, COLOR_BLUE);
        init_pair(ColorScheme::player2, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(ColorScheme::player3, COLOR_BLACK, COLOR_YELLOW);
        init_pair(ColorScheme::neutral, COLOR_WHITE, COLOR_GREEN);
        init_pair(ColorScheme::enviroment, COLOR_BLACK, COLOR_WHITE);
        init_pair(ColorScheme::damaged, COLOR_RED, COLOR_WHITE);
    }

    void begin() {
        start_color();
        initColorPairs();
    }

    void step() {
        refresh();
    }

    void end() {}

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