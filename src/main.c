#include <string.h>
//#include <stdio.h>
//#include <ncurses.h>

#include <stdio.h>

#ifndef __clang__
#include <malloc.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <curses.h>


void tela_verde(){
  
  int j,i;
  

    for(j=5;j<=20;j++){                   
      for(i=15;i<=71;i++){
         printf(" ");
      }
    }                            
}

int main(int argc, char *argv[])
{	


  tela_verde();

	return 0;
}

/*
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
*/