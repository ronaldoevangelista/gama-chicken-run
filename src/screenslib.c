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
	textcolor(GREEN);
	gotoxy((center - 6),4);
	printf("Game Fuga das Galinhas");
	gotoxy(25,5);
	printf("Dolores e uma Galinha revoltada que vive tentando fugir do Galinheiro.");
	gotoxy(15,6);
	printf("Apos colocar um certo numero de ovos, as galinhas são abatidas e viram recheio para tortas.");
	gotoxy(35,7);
	printf("Ajude Dolores a fugir com suas companheiras.");
	textcolor(7);	
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
	textbackground(BLACK); 	
                                   
}

void menuStartGame()
{
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
			gotoxy((center - 6),10); 
			cprintf("Escolha uma opcao");                                                                                     
			gotoxy((center - 6),12); 
			cprintf("[ 1 ] - [ Novo Game]\n");
			gotoxy((center - 6),13); 
			cprintf("[ 2 ] - [ Sair     ]");
			textbackground(BLACK);	
			gotoxy((center - 6),14); 
			cprintf("[   ] - [ ENTER    ]");
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
					screenBlue();
					break;
				case 2:clrscr();  
					break;                                   
			} 
	} while (readOption != 2);
}

void startNewGame()
{
	int cols;
	
	getScreenSize();
	headBar();
	playGame(); 
	system("cls");   
}

void screenBlue()
{
	j = 0;
	i = 0,
	getScreenSize();
	
	lns    = gwrows - 4; 
	cols   = gwcols - 5; 
	system("cls"); 				
	textbackground(BLUE);

	for(i=5;i<=cols;i++)
	{ 	
		for(j=6;j<=lns;j++)
		{
			gotoxy(i,j);
			printf(" ");  
		} 
	}
	
	center = gwcols /2;
	textcolor(7);
	gotoxy((center - 8),8);
	printf("Game Fuga das Galinhas");
	gotoxy(25,11);
	printf("Ajude Dolores a escapar do Galinheiro com suas companheiras esta noite.");
	gotoxy(25,12);
	printf("Dolores tem as seguintes habilidades, que podem ser usadas com um custo.");
	gotoxy(25,13);
	printf("Dolores pode se [Esconder], pode [Correr] e pode [Bicar] seus inimigos.");
	textcolor(7);
	
	gotoxy((center - 3 ),17); 	
	cprintf("[  OK  ]");	
	textbackground(BLACK);
	    
	int op;
	gotoxy((center - 3 ),17); 
	scanf("%i", &op);  
	getchar(); 	
	textbackground(BLACK);
}

void headBar()
{
	getScreenSize();
	
	j =0;
	i =0,
	
	lns    = gwrows - 4; 
	cols   = gwcols - 5; 
	center = gwcols /2;
	
	gotoxy((center - 6),2);
	printf("Game Fuga das Galinhas");
	gotoxy(5,6);
	
	for(j=5;j<=cols;j++)
	{
		printf("-");  
	} 

	gotoxy(5,3);
	for(j=5;j<=cols;j++)
	{
		printf("-");  
	} 
		
	gotoxy((center - 32),4); 		
   	cprintf("Attack with what? [1] - Hide [2] - Run [3] - Attack with the beak [4] - Sair");
   	
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
		textbackground(BLACK);
		gotoxy((center - 16),11); 
		cprintf("Help Dolores escape the farmer");
		gotoxy((center - 16),13); 	
		cprintf("[  ] Choose option and enter");	
	    textbackground(BLACK);
}
void playGame()
{
	int readOption;
	int controll = 1;

	while(controll)
	{
		enemyMonster = 100;
		chickenhero  = 100;
		srand(time(NULL));	
	clrscr();	
		do{
			headBar();
			gameHeader();
	
			gotoxy((center -15 ),13); 
			scanf("%i", &readOption);  
			getchar(); 
			
			if(readOption==4)
			{
				controll = 0;
           		break;
			}	
					
			if(readOption==1)
			{
				hitAttack=randInt(10);	
				enemyMonster=enemyMonster-hitAttack;
				
				headBar();
				gameHeader();
				
				gotoxy((center -36),15);			
				cprintf("SWING! - By not having seen her the farmer was punished with  %i damage",hitAttack);
				
				if(chickenhero < 90){
        			chickenhero = chickenhero + 5;
        			gotoxy((center - 36 ),15);
        			cprintf("SWING! - By not having seen her the farmer was punished with  %i damage",chickenhero);
				}

				if(enemyMonster < 0)
		        {
					gotoxy((center -26),16);			
					cprintf("You have killed the monster you win!");
					enemyMonster = 0;
					headBar();
					gotoxy((center - 2),18);			
					cprintf("[OK]");
					gotoxy((center ),18);
					getchar(); 
		            break;
		        }
		        
		        hitAttack=randInt(8);
		        chickenhero=chickenhero-hitAttack;
        
        		headBar();		
			}
			else if(readOption==2) {
				
				clrscr();		
				
				hitAttack=randIntLightning(10);
				enemyMonster=enemyMonster-hitAttack;
				
				if(hitAttack < 8)
				{
					chickenhero = chickenhero - hitAttack;
				}
				
				headBar();
				gameHeader();
        		
        		gotoxy((center -36),15);			
				cprintf("The gods are helping you, comes to your aid CLAAASH! %i damage",hitAttack);
				
				
				if(enemyMonster < 0)
		        {
					gotoxy((center -26),16);			
					cprintf("You have killed the monster you win!");
					enemyMonster = 0;
					headBar();
					gotoxy((center - 2),18);			
					cprintf("[OK]");
					getchar(); 
		            break;
		        }
								
			}
			/*
			else (readOption==3)
			{
				hitAttack=randIntFist(10);
        		enemyMonster=enemyMonster-hitAttack;

				headBar();
				gameHeader();
        		
        		gotoxy((center -36),15);			
				cprintf("The farm  run. Attack with the beak cause %i damage",hitAttack);
				
			}
			*/
			
			textbackground(BLACK);
		}
		while(controll);
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



