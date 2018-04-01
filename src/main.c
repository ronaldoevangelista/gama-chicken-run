#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include <fwindows.h>

#define WORLD_WIDTH 80
#define WORLD_HEIGHT 20

#define MAIN_WIN_COLOR 1

  int offsetx, offsety;
  int lcolx;				

  WINDOW *snakeys_world;
  WINDOW *win1;
  WINDOW *pwin;


int main(int argc, char *argv[])
{	

  WINDOW *my_win;
	
  int startx, starty, width, height;
	
  int ch;

	initscr();		
	cbreak();			
	curs_set(FALSE);
  start_color();

  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);

  attron(COLOR_PAIR(1));
  keypad(stdscr, TRUE);

	height = 30;
	width  = 40;
	
  starty = (LINES - height) / 2;
  startx = (COLS  - width)  / 2;	

  p_main_window(pwin);
 
  my_win = create_newwin(height, width, starty, startx);
/*
	while((ch = getch()) != KEY_F(1))
	{	
    switch(ch)
		{
     
  case KEY_LEFT:
        destroy_win(my_win);
        my_win = create_newwin(height, width, starty,--startx);
        break;
      case KEY_RIGHT:
        destroy_win(my_win);
        my_win = create_newwin(height, width, starty,++startx);
        break;
      case KEY_UP:
        destroy_win(my_win);
        my_win = create_newwin(height, width, --starty,startx);
        break;
      case KEY_DOWN:
        destroy_win(my_win);
        my_win = create_newwin(height, width, ++starty,startx);
        break;	
      case 10:
      clrtoeol();
       mvprintw(20, (lcolx + (lcolx/2) ), "Item selected is");
      refresh();
        paint_window(win1);

      break;  
		}
	}
	*/	
	endwin();		
	return 0;
}


/*
#include <curses.h>

int main(int argc, char** argv)
{
  initscr();

  printw("Main window");

  WINDOW* subwindow = newwin(10,20,5,15);

  refresh();

  box(subwindow,0,0);
  mvwprintw(subwindow, 1, 1, "subwindow");


  refresh();
  wrefresh(subwindow);

  getch();
  delwin(subwindow);

  endwin();
  return 0;
}
*/
/*
int main(int argc, char *argv[]) 
{

    initscr();
    refresh();
    curs_set(FALSE);

    offsetx = (COLS  - WORLD_WIDTH)  / 2;
    offsety = (LINES - WORLD_HEIGHT) / 2;
 
	  mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");

    snakeys_world = newwin(WORLD_HEIGHT, WORLD_WIDTH, offsety, offsetx);

    box(snakeys_world, 0 , 0);
    wrefresh(snakeys_world);
   // getch();
    delwin(snakeys_world);

    refresh();

    while((c = getch()) != KEY_F(1))
    {       
      switch(c)
      {	
        case KEY_DOWN:
          mvprintw(20, 0, "Item selected is KEY_DOWN" );
          break;
          case KEY_UP:
          mvprintw(20, 0, "Item selected is KEY_UP" );
          break;
          case 10:
          move(20, 0);
          clrtoeol();
          mvprintw(20, 0, "Item selected is enter" );
          break;
     }
    }

    endwin();

    return 0;
}
*/