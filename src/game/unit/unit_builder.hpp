#include <string>
#include "unit.hpp"

#pragma once

namespace unit {
    class UnitBuilder {
    private:
    public:
        UnitBuilder();

        Unit create();

        void config(std::string& file);
    };
}