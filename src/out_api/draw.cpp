#include <cstdlib>
#include <curses.h>
#include "draw.hpp"

namespace draw {
    void initColorPairs() {
        init_pair(static_cast<short>(ColorScheme::simple), COLOR_WHITE, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::map_simple), COLOR_WHITE, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::map_active), COLOR_BLACK, COLOR_WHITE);
        init_pair(static_cast<short>(ColorScheme::menu_simple), COLOR_WHITE, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::menu_active), COLOR_BLACK, COLOR_WHITE);
        init_pair(static_cast<short>(ColorScheme::player0), COLOR_RED, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::player1), COLOR_BLUE, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::player2), COLOR_MAGENTA, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::player3), COLOR_YELLOW, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::neutral), COLOR_GREEN, COLOR_WHITE);
        init_pair(static_cast<short>(ColorScheme::enviroment), COLOR_WHITE, COLOR_BLACK);
        init_pair(static_cast<short>(ColorScheme::damaged), COLOR_WHITE, COLOR_RED);
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

    void drawCh(size_t x, size_t y,
        Cell cell, ColorScheme colorScheme) {
        attron(COLOR_PAIR(colorScheme));
        mvaddch(y, x, static_cast<short>(cell));
        attroff(COLOR_PAIR(colorScheme));
    }

    void drawKey(size_t x, size_t y,
        char key, ColorScheme colorScheme) {
        attron(COLOR_PAIR(colorScheme));
        mvaddch(y, x, key);
        attroff(COLOR_PAIR(colorScheme));
    }

    void getSize(size_t& x, size_t& y) { // is it work ??
        getmaxyx(stdscr, y, x);
    }
}
