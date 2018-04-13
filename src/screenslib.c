#include "screenslib.h"

int gwcols = 0;
int gwrows = 0;
int center = 0;

int lns = 0;
int cols = 0;

int i = 0;
int j = 0;

int hitAttack    = 0;
int enemyMonster = 0;
int chickenhero  = 0;


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
	lines();
	center = gwcols /2;
	gotoxy((center - 6),4);
	printf("Game chicken run");
    textbackground(BLACK);	    
}

void lines()
{
	getScreenSize();
	textbackground(BLACK);
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

void erro()
{         
    system("cls");                                 
	int j,i;
	textbackground(RED);
	for(j=5;j<=23;j++){                   
		for(i=15;i<=65;i++){
			gotoxy(i,j); printf(" ");
		}
	}  
	int op;
	scanf("%d", &op);                                   
}
void menuStartGame()
{
	textbackground(BLACK); 	
	getScreenSize();
	createStartGame();
	
	int readOption;
	center = gwcols /2;

	do
	{ 
		do
		{
			textcolor(7);
			createStartGame();	
			gotoxy((center -10),10); 
			cprintf("Choose Option 1 or 2 and ENTER");                                                                                     
			gotoxy((center - 6),11); 
			cprintf("[ 1 ] - [ New Game ]\n");
			gotoxy((center - 6),12); 
			cprintf("[ 2 ] - [ Exit     ]");
			textbackground(YELLOW);	
			gotoxy((center - 6),14); 
			cprintf("[                  ]");
	        gotoxy((center - 4),14); 
			scanf("%d", &readOption);                 
			gotoxy((center - 6),15); 
			getchar();   
			textcolor(7);
			clrscr();
	        textbackground(BLACK);
				                  
		}
		while((readOption<1)||(readOption>2));
			switch (readOption)
			{
				case 1:clrscr();  
					startNewGame();
					break;
				case 2:clrscr();  
					break;                                   
			} 
			textbackground(BLACK);	
	} while (readOption != 2);
	textbackground(BLACK); 
}


void startNewGame()
{
	int cols;
	
	getScreenSize();
	textbackground(BLACK);
	headBar();
	screenBlue();
	textbackground(BLACK);	  
	playGame(); 
	system("cls");   
}

void screenBlue()
{
	j = 0;
	i = 0,
	
	lns    = gwrows - 4; 
	cols   = gwcols - 5; 
					
	textbackground(BLUE);

	for(i=5;i<=cols;i++)
	{ 	
		for(j=10;j<=lns;j++)
		{
			gotoxy(i,j);
			printf(" ");  
		} 
	}
	textbackground(BLACK);	  
}

void headBar()
{
	getScreenSize();
	textbackground(BLACK);
	
	j =0;
	i =0,
	
	lns    = gwrows - 4; 
	cols   = gwcols - 5; 
	center = gwcols /2;
	
	gotoxy((center - 6),2);
	printf("Game chicken run");
	gotoxy(5,6);
	
	for(j=5;j<=cols;j++)
	{
		printf("-");  
	} 

	textbackground(BLACK);
	gotoxy(5,3);
	for(j=5;j<=cols;j++)
	{
		printf("-");  
	} 
	
	textbackground(BLACK);	
	
	gotoxy((center - 32),4); 		
   	cprintf("Attack with what? [1] - Hide [2] - Run [3] - Attack with the beak");
   	
	gotoxy(5,5); 
	textbackground(RED);
	printf("Current Health   %d%%    " ,chickenhero);         
	textbackground(BLACK);	
	  
	gotoxy((cols-20),5); 
	textbackground(RED);
	printf("Enemy Health   %d%%    " ,enemyMonster);         
	textbackground(BLACK);
}

void gameHeader()
{
		textbackground(BLUE);
		gotoxy((center - 16),11); 
		cprintf("Help Dolores escape the farmer");
		gotoxy((center - 16),13); 	
		textbackground(WHITE);	
		cprintf(" [  ] Choose option and enter ");	
		textbackground(BLUE);   
}
void playGame()
{
	int readOption;

	while(1)
	{
		enemyMonster = 100;
		chickenhero  = 100;
		srand(time(NULL));
		
		headBar();
		gameHeader();
		textbackground(BLACK);	
		
		do{
			gotoxy((center -14 ),13); 
			scanf("%i", &readOption);  
			getchar(); 
			
					
			if(readOption==1)
			{
			
				hitAttack=randInt(10);	
				enemyMonster=enemyMonster-hitAttack;
				
				textbackground(BLUE);   						
				gotoxy((center -36),15);			
				cprintf("SWING! - By not having seen her the farmer was punished with  %i damage",hitAttack);
				
				if(chickenhero < 90){
        			chickenhero = chickenhero + 5;
        			gotoxy((center - 36 ),15);
					textbackground(BLUE);
        			cprintf("SWING! - By not having seen her the farmer was punished with  %i damage",chickenhero);
        			textbackground(BLACK);
				}
				
        		headBar();		

        		textbackground(BLACK);
			}
			else if(readOption==2) {

				textbackground(BLACK);
				headBar();
				
				gotoxy((center -36),15);			
				cprintf("The gods are helping you, comes to your aid CLAAASH! %i damage",hitAttack);
        		textbackground(BLACK);  
        		
				
				/*
				textbackground(BLACK);  
				
				hitAttack=randIntLightning(10);
				enemyMonster=enemyMonster-hitAttack;
				
				headBar();
				textbackground(BLACK);
				gotoxy((center -36),15);
				
				textbackground(BLUE);        		
				cprintf("The gods are helping you, comes to your aid CLAAASH! %i damage",hitAttack);
		        textbackground(BLACK);
				if(enemyMonster < 0)
		        {
		            printf("You have killed the monster you win!\n\n");
		            break;
		        }
       			textbackground(BLACK);
        */
			}
			textbackground(BLACK);
		}
		while(1);
	}
}

int randInt(int n)
{
	return rand()%n + 10;
}

int randIntLightning(int n)
{    
	return rand()%n + 20;	
}

int randIntFist(int n)
{
	return rand()%n +2;
}



