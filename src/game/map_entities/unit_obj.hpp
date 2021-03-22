#include <utility>
#include <cstdint>
#include "cell.hpp"
#include "../unit/unit.hpp"

#pragma ONCE

namespace map {
    class UnitObj {
    private:
        Unit* unit;
        std::pair<int32_t, int32_t> pos;
        std::pair<int32_t, int32_t> size;
        CellType cellType;      
    public:
        UnitObj(Unit* unit) : unit(unit) {

        }
        void updateValues() {
            // from unit size, pos
        }
        void updatePosition() {
            // from unit position
        }
        void updateAll() {

        }
    };
}