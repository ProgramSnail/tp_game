#include "game_draw.hpp"
#include "draw.hpp"

namespace game_draw {
    const size_t MENU_WIDTH = 16;

    const size_t MENU_ENTITY_EXTRA = 4;

    const draw::ColorScheme menuSimpleScheme =
        draw::ColorScheme::menu_simple;

    const draw::ColorScheme menuActiveScheme =
        draw::ColorScheme::menu_active;

    size_t lastWidth = 0;

    size_t lastHeight = 0;

    void drawMenuEntity(size_t pos, size_t start, size_t end,
        char shortkey, draw::Cell type,
        const std::string& name, bool isActive) {
        draw::ColorScheme colorScheme =
            isActive ? menuActiveScheme : menuSimpleScheme;
        draw::drawKey(start, pos, shortkey, colorScheme);
        draw::drawCh(start + 1, pos, draw::Cell::blank, colorScheme);
        for (size_t i = 0; i <= end - start - MENU_ENTITY_EXTRA; ++i) {
            if (i < name.size()) {
                draw::drawKey(start + 2 + i, pos,
                    name[i], colorScheme);
            } else {
                draw::drawCh(start + 2 + i, pos,
                    draw::Cell::blank, colorScheme);
            }
        }
        // ?? add move of name ??
        draw::drawCh(end - 1, pos, draw::Cell::blank, colorScheme);
        draw::drawCh(end, pos, type, colorScheme);
    }
    
    void drawMenu(std::pair<size_t, size_t> start,
        std::pair<size_t, size_t> end) {
        for (size_t i = start.second; i <= end.second; ++i) {
            // add real entities
            drawMenuEntity(i, start.first, end.first, 'A',
                draw::Cell::unit, "Tank", false);
        }
    }

    void drawMap(std::pair<size_t, size_t> start,
        std::pair<size_t, size_t> end) {
        
    }

    void drawParams(std::pair<size_t, size_t> start,
        const std::vector<std::pair<int, draw::Cell>> &res) {
        size_t pos = start.first;
        for (size_t i = 0; i < res.size(); ++i) {
            std::string s = std::to_string(res[i].first);
            for (size_t j = 0; j < s.size(); ++j, ++pos) {
                draw::drawKey(pos, start.second,
                    s[j], menuSimpleScheme);
            }
            draw::drawCh(pos++, start.second, 
                res[i].second, menuSimpleScheme);
            draw::drawCh(pos++, start.second,
                draw::Cell::blank, menuSimpleScheme);
        }
    }

    void drawRequirements(std::pair<size_t, size_t> end,
        const std::vector<draw::Cell> &requirements) {
        size_t pos = end.first;
        for (size_t i = 0; i < requirements.size(); ++i) {
            draw::drawCh(pos--, end.second,
                requirements[i], menuSimpleScheme);
            draw::drawCh(pos--, end.second,
                draw::Cell::blank, menuSimpleScheme);
        }
        draw::drawCh(pos, end.second,
            draw::Cell::menu_vb, menuSimpleScheme);
    }

    void drawAll() {
        size_t width;
        size_t height;
        draw::getSize(width, height);
        // check width && height

        size_t menuBorderLeft = width - MENU_WIDTH - 3;
        size_t menuBorderDown = height - 3;
        size_t borderUp = 1;
        size_t borderDown = height - 1;
        size_t borderLeft = 0;
        size_t borderRight = width - 1;

        if (width != lastWidth || height != lastHeight) {
            draw::clearAll();
        }

        // draw borders
        for(size_t i = borderUp + 1; i < borderDown; ++i) {
            draw::drawCh(0, i,
                draw::Cell::menu_vb, menuSimpleScheme);
            draw::drawCh(menuBorderLeft, i,
                draw::Cell::menu_vb, menuSimpleScheme);
            draw::drawCh(borderRight, i,
                draw::Cell::menu_vb, menuSimpleScheme);
        }
        for(size_t i = borderLeft + 1; i < borderRight; ++i) {
            draw::drawCh(i, borderUp, draw::Cell::menu_hb,
                menuSimpleScheme);
            draw::drawCh(i, borderDown, draw::Cell::menu_hb, 
                menuSimpleScheme);
        }
        for (size_t i = menuBorderLeft + 1; i < borderRight; ++i) {
            draw::drawCh(i, menuBorderDown, draw::Cell::menu_hb,
                menuSimpleScheme);
        }

        // draw corners
        {
            std::vector<std::pair<size_t, size_t>> corners = {
                {borderLeft, borderUp},
                {menuBorderLeft, borderUp},
                {borderRight, borderUp},
                {menuBorderLeft, menuBorderDown},
                {borderRight, menuBorderDown},
                {borderLeft, borderDown},
                {menuBorderLeft, borderDown},
                {borderRight, borderDown}
            };
            for (size_t i = 0; i < corners.size(); ++i) {
                draw::drawCh(corners[i].first,
                    corners[i].second, draw::Cell::menu_c,
                        menuSimpleScheme);
            }
        }

        drawMenu({menuBorderLeft + 1, borderUp + 1},
            {borderRight - 1, menuBorderDown - 1});

        drawMap({borderLeft + 1, borderUp + 1}, 
            {menuBorderLeft - 1, borderDown - 1});

        // resources
        drawParams({0, 0}, std::vector<std::
            pair<int, draw::Cell>>({
                {1023, draw::Cell::gold},
                {324, draw::Cell::iron},
                {545, draw::Cell::tech}
            })); // test

        // draw build requirements
        drawRequirements({width - 1, 0}, std::
            vector<draw::Cell>(5, draw::Cell::unit)); // test
        
        // cost
        drawParams({menuBorderLeft + 1, menuBorderDown + 1},
            std::vector<std::pair<int, draw::Cell>>({
                {120, draw::Cell::gold},
                {400, draw::Cell::iron},
                {15, draw::Cell::tech}
            })); // test

        lastWidth = width;
        lastHeight = height;
    }   
}
