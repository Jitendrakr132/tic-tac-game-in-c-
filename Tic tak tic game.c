#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>


#define ANSI_COLOR_RED"\x1b[31m"
#define ANSI_COLOR_BLUE"\x1b[32m"
#define ANSI_COLOR_RESET"\x1b[0m"
char s[10]={'0','1','2','3','4','5','6','7','8','9'};
int checkwin();
void dashboard();
int menu ()
{
    int choice;
    printf("\n 1.want to play with smart computer:");
    printf("\n 2.Want to play with Evil computer");
    printf("\n 3. Want to play with player");
    printf("\n 4.Exit");
    printf("\n\nEnter your choice:");
    scanf("%d",&choice);
    return choice;
}
int main()
{
    while(1)
    {
        switch(menu())
        {
       case 1:
           player_with_player();
           break;
       case 4:
           exit(0);
           default:
               printf("Invalid option");
        }
        getch();
    }
}
    void player_with_player()
    {
    int player=1,i,choice;
    char mark; //x,0
    do{
        dashboard();
    player=(player%2)?1:2;
    printf("player %d,Enter the choice:",player);
    scanf("%d",&choice);
    mark=(player==1)?'x':'0';
    if(choice==1&&s[1]=='1')
        s[1]=mark;
     else if(choice==2&&s[2]=='2')
        s[2]=mark;
     else if(choice==3&&s[3]=='3')
        s[3]=mark;
     else if(choice==4&&s[4]=='4')
        s[4]=mark;
     else if(choice==5&&s[5]=='5')
        s[5]=mark;
     else if(choice==6&&s[6]=='6')
        s[6]=mark;
     else if(choice==7&&s[7]=='7')
        s[7]=mark;
      else if(choice==8&&s[8]=='8')
        s[8]=mark;
      else if(choice==9&&s[9]=='9')
        s[9]=mark;
        else
        {
            printf("Invalid option");
            player--;
            getch();
        }
        i=checkwin();
        player++;
    }while(i==-1);
    dashboard();
    if(i==1)
    {
        printf("==> player %d won",--player);
    }
    else
    {
        printf("==> Game over");
    }
    }
       int checkwin()
    {
        if(s[1]==s[2]&&s[2]==s[3])
            return 1;
        else if(s[4]==s[5]&&s[5]==s[6])
            return 1;
        else if(s[7]==s[8]&&s[8]==s[9])
            return 1;
        else if(s[1]==s[5]&&s[5]==s[9])
            return 1;
        else if(s[3]==s[5]&&s[5]==s[7])
            return 1;
        else if(s[1]==s[4]&&s[4]==s[7])
            return 1;
         else if(s[2]==s[5]&&s[5]==s[8])
            return 1;
         else if(s[3]==s[6]&&s[6]==s[9])
            return 1;
        else if(s[1]!='1'&&s[2]!='2'&&s[3]!='3'&&s[4]!='4'&&s[5]!='5'&&s[6]!='6'&&s[7]!='7'&&s[8]!='8'&&s[9]!='9')
            return 0;
        else
            return -1;

    }
    void dashboard()
    {
        system("cls");
        printf(ANSI_COLOR_BLUE"\n\n\t ### ## ##  Tic Tic Toc ## ## ###\n\n"ANSI_COLOR_RESET);
        printf("player 1(x)- player 2(0)\n\n\n");
        printf(ANSI_COLOR_RED"  |  |   \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED" %c| %c| %c \n"ANSI_COLOR_RESET,s[1],s[2],s[3]);
        printf(ANSI_COLOR_RED"__|__|___\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED"  |  |   \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED" %c| %c| %c \n"ANSI_COLOR_RESET,s[4],s[5],s[6]);
        printf(ANSI_COLOR_RED"__|__|___\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED"  |  |   \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED" %c| %c| %c \n"ANSI_COLOR_RESET,s[7],s[8],s[9]);
        printf(ANSI_COLOR_RED"  |  |   \n"ANSI_COLOR_RESET);

    }
