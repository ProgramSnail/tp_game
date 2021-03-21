#include <curses.h>
#include <cstdlib>
#include <unistd.h>

int main() {
    size_t y;
    size_t x;
    initscr();
    noecho();
    curs_set(false);
    for (size_t i = 0; ; ++i) {
        clear();
        getmaxyx(stdscr, y, x);
        mvprintw(i % y, i % x, "Hello World!");
        refresh();
        usleep(30000);
    }
    endwin();
}