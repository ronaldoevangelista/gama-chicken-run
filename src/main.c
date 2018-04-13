#include <stdio.h>
#include <conio2.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>



void linhas();

int main(int argc, char *argv[])
{
	
	clrscr();
	textbackground(BLACK);       
	linhas();  
	system("pause");
	return 0;
}

void linhas(){
gotoxy(16,8); printf("-----------------------------------------------");   
gotoxy(16,20);printf("-----------------------------------------------");  
}
