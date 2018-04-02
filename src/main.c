#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include <fwindows.h>

#define WORLD_WIDTH 80
#define WORLD_HEIGHT 20

#define MAIN_WIN_COLOR 1

  WINDOW *pwin;

int main(int argc, char *argv[])
{	
	initscr();		
	cbreak();			
	curs_set(FALSE);
  start_color();

  keypad(stdscr, TRUE);

  p_main_window(pwin);
 
  startscreen();
	endwin();		
	return 0;
}
