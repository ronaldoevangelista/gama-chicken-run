#include <fwindows.h>
#include <string.h>

char *choices[] = { 
			"[1 - New  ]",
			"[2 - Load ]",
			"[3 - Exit ]",
		  };

int c;
int ch;
int choice = 0;
int highlight = 1;
int n_choices = sizeof(choices) / sizeof(char *);
WINDOW *wingstart;

WINDOW *my_win;
WINDOW *menu_win;
WINDOW *local_win;

int gstartx, gstarty, gwidth, gheight;

void startscreen()
{
    gheight = 10;
    gwidth  = 80;

    gstarty = (LINES - gheight) / 2;
    gstartx = (COLS  - gwidth)  / 2 ;	 
    my_win = create_newwin(gheight, gwidth, gstarty, gstartx);
   // p_main_window(menu_win);

}

void p_main_window(WINDOW *pwin)
{
    int x, y , p , c;
    char mesg[]="Welcome to the chicken escape game.";	
    
    refresh();
    
    clear();
    
    refresh();
    
    getmaxyx(stdscr, y, x);
    
    refresh();

    pwin = newwin(y - 4, x - 4, 1, 2);
    
    box(pwin, 0, 0);
    
    p = ((x -4)/2) - strlen(mesg) / 2 ;
    
    mvwprintw(pwin, 1, p, "%s",mesg);
    
    wrefresh(pwin);
}

void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 35;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	
        if(highlight == i + 1) 
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
        {
			mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
		++y;
	}
	wrefresh(menu_win);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	
    char mesg[255];	


	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);	
    
    keypad(local_win, TRUE);
    printmsg(local_win, 1);

    refresh();
	print_menu(local_win, highlight);

    while((ch = getch()) != KEY_F(1))
	{	
		switch(ch)
		{	case KEY_UP:
				if(highlight == 1)
                {
					highlight = n_choices;
                }
				else
                {
					--highlight;
                }
                printmsg(local_win, highlight);
                refresh();
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
                {
					highlight = 1;
                }
				else
                {
					++highlight;
                }
                printmsg(local_win, highlight);  
				break;
			case 10:
                if(highlight < 3)
                {
                //startscreen();
                
                //destroy_win(local_win);

                }else if(highlight == 3)
                {
                    return 0;
                }
                clrtoeol();
                refresh();
				break;
			default:
				break;
		}
		print_menu(local_win, highlight);
        clrtoeol();
		if(choice != 0)
        {
			break;
        }
	}
	wrefresh(local_win);		
	return local_win;
}

void printmsg(WINDOW *l_win, int option)
{
    char lmesg[255];
    if(option == 1 ){
        strcpy(lmesg,"New Game. Help the chickens escape!");
    }
    else if(option == 2 ){
        strcpy(lmesg,"Load Game. Not implement yet!");
    }
    else {
        strcpy(lmesg,"Exit Game!");
    }
    werase(l_win);
    mvwprintw(l_win, 7, 20, " %d - %s",option, lmesg);
    wrefresh(l_win);
    clrtoeol();
    refresh();
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}

void print_ttitle(int lcols)
{
  	attron(COLOR_PAIR(2));
	mvprintw(2, (lcols + (lcols / 2)), "Press <ENTER> to see the option selected");
    refresh();
}

void new_window(WINDOW *pwin, char title[])
{
    int x, y , p , c;
    char mesg[255];	
    
    refresh();
    
    clear();
    
    refresh();
    
    getmaxyx(stdscr, y, x);
    
    refresh();

    pwin = newwin(y - 4, x - 4, 1, 2);
    
    box(pwin, 0, 0);
    
    p = ((x -4)/2) - strlen(mesg) / 2 ;
    
    strcpy(mesg,title);
    mvwprintw(pwin, 1, p, "%s",mesg);
    
    wrefresh(pwin);
}

void paint_window(WINDOW *win1)
{
    int startx, starty, width, height;    

    refresh();
    clear();
    refresh();

    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);

    bkgd(COLOR_PAIR(1));
    refresh();

	height = 10;
	width  = 80;
        
    starty = (LINES - height) / 2;
    startx = (COLS  - width)  / 2 ;	

    win1 = newwin(height, width, starty, startx);    
    box(win1, 0, 0);
    wrefresh(win1);
}