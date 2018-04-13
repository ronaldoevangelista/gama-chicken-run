#include <stdio.h>
#include <conio2.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "screenslib.h"


void erro();


void main(int argc, char *argv[])
{
	clrscr();
 	createStartGame();
 	
 	
	printf("\n\n\n\n\n\n\n\n\n");
	return;
}


void erro()
{                                                
	int j,i;
	
	getScreenSize();
		
	textbackground(RED);
/*	
	for(j=0;j<=gwcols;j++)
	{                   
		for(i=0;i<=gwrows;i++)
		{
			gotoxy(i,j);
			printf(" ");
		}
	}   
	*/                         
} 
                 

