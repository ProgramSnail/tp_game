#include "draw.hpp"
#include "game_draw.hpp"

namespace game_draw {
    const size_t MENU_WIDTH = 16;
    
    void drawAll() {
        size_t width;
        size_t height;
        draw::getSize(width, height);
        // check width && height
        for(size_t i = 0; i < height; ++i) {
            draw::drawCh(i, 0, draw::Cell::menu_hb);
            draw::drawCh(i, width - 1, draw::Cell::menu_hb);
            draw::drawCh(i, width - MENU_WIDTH, draw::Cell::menu_hb);
        }
        for(size_t i = 0; i < width; ++i) {
            draw::drawCh(0, i, draw::Cell::menu_vb);
            draw::drawCh(height - 1, i, draw::Cell::menu_vb);
        }
        // draw corners
    }   
    
    void drawMenu(std::pair<size_t, size_t> start, std::pair<size_t, size_t> end) {
        
        
    }
    
    void drawMap(std::pair<size_t, size_t> start, std::pair<size_t, size_t> end) {
        
    }
}
