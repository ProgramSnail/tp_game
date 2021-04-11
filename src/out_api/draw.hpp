#include <cstdint>

#pragma once

namespace draw {
    using std::size_t;

    enum class ColorScheme {
        simple = 0,
        map_simple = 1,
        map_active = 2,
        menu_simple = 3,
        menu_active = 4,
        player0 = 5,
        player1 = 6,
        player2 = 7,
        player3 = 8,
        neutral = 9,
        damaged = 10,
        enviroment = 11,
    };

    enum class Cell {
        blank = ' ',
        menu_hb = '-',
        menu_vb = '|',
        menu_c = ' ',
        field = '.',
        mountain = '^',
        unit = '#',
        gold = 'G',
        iron = 'I',
        tech = 'T'
    };

    void begin();

    void step();
    
    void end();

    void clearAll();

    void drawCh(size_t x, size_t y,
        Cell cell, ColorScheme colorScheme = ColorScheme::simple);

    void drawKey(size_t x, size_t y,
        char key, ColorScheme colorScheme = ColorScheme::simple);

    // void setxy(uint32_t x, uint32_t y);

    void getSize(size_t& x, size_t& y);
}
