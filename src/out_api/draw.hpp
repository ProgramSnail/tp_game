#include <cstdint>

#pragma ONCE

namespace draw {

    enum ColorScheme {
        simple,
        active,
        player0,
        player1,
        player2,
        player3,
        neutral,
        damaged,
        enviroment
    };

    enum Cell {
        blank = ' ',
        menu_h = '-',
        menu_v = '|',
        field = '.',
        mountain = '^',
        unit = '#'
    };

    void begin();

    void step();
    
    void end();

    void clearAll();

    void drawCh(uint32_t x, uint32_t y,
        Cell cell, ColorScheme colorScheme = ColorScheme::simple);

    // void setxy(uint32_t x, uint32_t y);

    void getSize(uint32_t& x, uint32_t& y);
}
