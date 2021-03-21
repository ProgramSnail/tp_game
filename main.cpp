#include <curses.h>
#include <cstdlib>
#include <unistd.h>

int main() {
    initscr();
    noecho();
    mvprintw(0, 0, "Hello World!");
    refresh();
    sleep(1);
    curs_set(false);
    endwin();
}