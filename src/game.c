#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game();
int main()
{
    int x;

    do{

    printf("Do you want to play a game 1 for yes 0 for no\n");

    scanf("%i",&x);

    if(x==1)
       play_game();

    else if(x==0)
	printf("You're no fun!\n");
        break;
    }while(1);

system("pause");
return 0;
}

void play_game()
{

    int x,hit,monster,hero;
    while(1){
    monster=60;
    hero=60;
    int rand_int(int n);
    int rand_int_lightning(int n);
    int rand_int_fist(int n);
    srand(time(NULL));

do{


   printf("\nCurrent Health: %i\nAttack with what?\n 1:Sword\n 2:Lighting\n 3:Fist\n\n",hero);
   scanf("%i",&x);

if(x==1)
{

        hit=rand_int(10);
        monster=monster-hit;
        printf("\nSWING!! Damage %i\n\n",hit);
        if(monster < 0)
        {
            printf("You have killed the monster you win!\n\n");
            break;
        }
        printf("The monsters life points are now %i\n\n",monster);
        hit=rand_int(10);
        hero=hero-hit;
        printf("The monster takes a swing BANG! Damage %i!\n",hit);
        if(hero < 0)
        {
            printf("You have been killed you lose\n\n");
            break;
        }
}
else if(x==2)
{
        hit=rand_int_lightning(10);
        monster=monster-hit;
        printf("\nThe god Zues comes to your aid CLAAASH!! Damage %i\n\n",hit);
        if(monster < 0)
        {
            printf("You have killed the monster you win!\n\n");
            break;
        }
        printf("The monsters life points are now %i\n\n",monster);

        hit=rand_int(10);
        hero=hero-hit;
        printf("The monster takes a swing BANG! Damage %i!\n",hit);
        if(hero < 0)
        {
            printf("You have been killed you lose\n");
            break;
        }

}

else if(x==3)
{

        hit=rand_int_fist(10);
        monster=monster-hit;
        printf("\nPUNCH!! Damage %i\n\n",hit);
        if(monster < 0)
        {
            printf("You have killed the monster you win!\n\n");
            break;
        }
        printf("The monster life points are now %i\n",monster);
        hit-rand_int(10);
        hero=hero-hit;
        printf("\nThe monster takes a swing BANG! Damage %i!\n\n",hit);
        if(hero < 0)
        {
            printf("You have been killed you lose");
            break;
        }

}

}while(1);

    }
}
int rand_int (int n)
{
    return rand()%n + 10;
}
int rand_int_lightning (int n)
{
    return rand()%n + 20;
}
int rand_int_fist(int n)
{
    return rand()%n +2;
}
