#include <cstdint>

#pragma once

namespace draw {
    using std::size_t;

    enum ColorScheme {
        simple,
        map_simple,
        map_active,
        menu_simple,
        menu_active,
        player0,
        player1,
        player2,
        player3,
        neutral,
        damaged,
        enviroment,
    };

    enum Cell {
        blank = ' ',
        menu_hb = '-',
        menu_vb = '|',
        menu_c = ' ',
        field = '.',
        mountain = '^',
        unit = '#'
    };

    void begin();

    void step();
    
    void end();

    void clearAll();

    void drawCh(size_t x, size_t y,
        Cell cell, ColorScheme colorScheme = ColorScheme::simple);

    // void setxy(uint32_t x, uint32_t y);

    void getSize(size_t& x, size_t& y);
}
