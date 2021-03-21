#include <curses.h>
#include <cstdlib>

int main() {
    initscr();
    noecho();
    curs_set(false);
    endwin();
}