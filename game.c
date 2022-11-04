#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int snakeWaterGun(char you, char comp){
    // returns 1 if you win, -1 if you lose and 0 if draw
    // Condition for draw
    // Cases covered:
    // ss
    // gg
    // ww
    if(you == comp){
        return 0;
    }

    // Non-draw conditions
    // Cases covered:
    // sg
    // gs
    // sw 
    // ws
    // gw
    // wg
    
    if(you=='s' && comp=='g'){
        return -1;
    }
    else if(you=='g' && comp=='s'){
        return 1;
    }

    if(you=='s' && comp=='w'){
        return 1;
    }
    else if(you=='w' && comp=='s'){
        return -1;
    }

    if(you=='g' && comp=='w'){
        return -1;
    }
    else if(you=='w' && comp=='g'){
        return 1;
    }

}

void startGame()
{
    char you, comp;
    srand(time(0));
    int number = rand()%100 + 1;

    if(number<33){
        comp = 's';
    }
    else if(number>33 && number<66){
        comp='w';
    }
    else{
        comp='g';
    }
    
    printf("\n\t\t\t## Enter 'Q' or 'q' to Quit the Game..");
    printf("\n\t\t\t==> Enter 's' for snake, 'w' for water and 'g' for gun -->\n\t\t\t");
    fflush(stdin);
    scanf("%c", &you);

    if (you == 'q' || you == 'Q')
    {
        printf("\n\n\t\t\t ******* Thank You ******* \n");
        exit(0);
    }

    int result = snakeWaterGun(you, comp);
    if(result==0){
        printf("\n\t\t\tGame draw!\n");
    }
    else if(result==1){
        printf("\n\t\t\tYou win!\n");
    }
    else{
        printf("\n\t\t\tYou Lose!\n");
    }
    printf("\t\t\tYou chose %c and computer chose %c.\n\n", you, comp);

    startGame();
}

int main()
{
    system("cls");
    printf("\n\t\t\t ******* Snake-Water-Gun Game *******\n");
    startGame();
    return 0;
}