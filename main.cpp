#include <curses.h>
#include <cstdlib>

int main() {
    initscr();
    cbreak();
    noecho();
    clear();
    mvaddch(5, 5, '.');
}