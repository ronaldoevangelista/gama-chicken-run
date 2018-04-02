#include <string.h>
#include <stdio.h>
#include <ncurses.h>

void print_ttitle();

void paint_window(WINDOW *win1);

void p_main_window(WINDOW *win1);

void destroy_win(WINDOW *local_win);

WINDOW *create_newwin(int height, int width, int starty, int startx);

void print_menu(WINDOW *menu_win, int highlight);
void printmsg(WINDOW *l_win, int option);
