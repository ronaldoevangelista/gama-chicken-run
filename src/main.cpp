#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include "include/colors.h"



int main(int argc, char **argv){
    
    WINDOW* wnd;
    
    wnd = initscr();

    initscr();
    cbreak();
    noecho();
    clear();
    refresh();

    move(5, 5);

    // hide cursor
    curs_set(0);

   // std::string text = "Hello world!";
    char text[] = "Hello world!\0";

    size_t len = strlen(text);

    for(size_t i = 0; i < len; i++) {
        addch(text[i]);
        addch(' ');
    }


    start_color();

    // draw box around screen
    attron(A_BOLD);
    box(wnd, 0, 0);
    attroff(A_BOLD);

    refresh();

    while(1);

    endwin();
    return 0;
}

/*
int main()
{
    printf("Olá, mundo!");
    printf(FBLU("I'm blue."));

    return (0);
}
*/