#include <cstdint>

#pragma ONCE

namespace init {

    const uint32_t STEP_DELAY_USEC = 30000;

    void begin();

    void step();

    void end();    
}