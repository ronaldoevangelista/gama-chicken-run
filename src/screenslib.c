#include "screenslib.h"

int gwcols = 0;
int gwrows = 0;

void getScreenSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	gwcols = columns;
	
	gwrows = rows;	
}

void createStartGame()
{
	getScreenSize();
	
	int j,i, cols;
	
	gotoxy(16,8);
	 
	cols = gwcols - 32; 
	
	for(j=0;j<=cols;j++)
	{
		printf("-");  
	} 
	
	gotoxy(16,20);
	
	for(j=0;j<=cols;j++)
	{
		printf("-");  
	} 
	
	int center = gwcols /2;
	
	gotoxy((center - 6),4);
	
	printf("Game chicken run");
	
	 gotoxy((center -14),10); 
	 printf ("Choose Option 1 or 2 and ENTER");                                                                                     
     gotoxy((center - 6),11); 
	 printf ("[ 1 - New Game ]\n");
	 gotoxy((center - 6),12); 
	 printf ("[ 2 - Exit     ]");

	textbackground(YELLOW);	
	gotoxy((center - 6),14); 
	printf("                ");
	
	int dado;
    gotoxy((center - 6),14); 
	scanf("%d",&dado);
    fflush(stdin);
    textbackground(BLACK);

	
}


void lines()
{
	getScreenSize();
	
	int j,i, cols;
	
	gotoxy(16,8);
	 
	cols = gwcols - 32; 
	
	for(j=0;j<=cols;j++)
	{
		printf("-");  
	} 
	
	gotoxy(16,20);
	
	for(j=0;j<=cols;j++)
	{
		printf("-");  
	} 
}


