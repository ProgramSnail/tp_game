#include <vector>
#include "unit_module.hpp"
#include "unit_memory_elem.hpp"

#pragma ONCE

namespace unit {
    class Unit {
    private:
        std::vector<Module> modules;
        std::vector<MemoryElem> memory;
    public:
        Unit();
    };
}