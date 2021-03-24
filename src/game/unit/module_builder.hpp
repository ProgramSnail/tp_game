#include <string>
#include "unit_module.hpp"

#pragma once

namespace unit {
    class ModuleBuilder {
    private:
    public:
        ModuleBuilder();

        Module create();
        
        void config(const std::string& file);
    };
}