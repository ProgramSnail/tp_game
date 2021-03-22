#include <curses.h>
#include <cstdlib>
#include "src/out_api/init.hpp"

int main() {
    init::begin();
    for (; !init::stop();) {
        init::step();
    }
    init::end();    
}