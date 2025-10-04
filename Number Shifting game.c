#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>


#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET"\x1b[0m"


void creatmatrix(int arr[][4])
{
    int n=15;
    int num[n],i,j;
    for(i=0;i<15;i++)
        num[i]=i+1;

    srand(time(NULL));
    int lastIndex=n-1,index;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(lastIndex>=0)
            {
                index=rand()%(lastIndex+1);
                arr[i][j]=num[index];
                num[index]=num[lastIndex--];
            }
        }
        arr[i-1][j-1]==0;
    }
    void showmatrix(int arr[][4])
    {
        int i,j;
        printf(ANSI_COLOR_RED" ------------------\n"ANSI_COLOR_RESET);
        for(i=0;i<4;i++)
        {
            printf(ANSI_COLOR_YELLOW" | "ANSI_COLOR_RESET);
            for(j=0;j<4;j++)
            {
                if(arr[i][j]!=0)
                    printf(ANSI_COLOR_YELLOW"%2d |"ANSI_COLOR_RESET,arr[i][j]);
                else
                    printf(ANSI_COLOR_YELLOW"   | "ANSI_COLOR_RESET);
            }
            printf("\n");
            }
            printf(ANSI_COLOR_RED" ------------------\n"ANSI_COLOR_RESET);
    }
    int winner(int arr[][4])
    {
        int i,j,k=1;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++ ,k++)
                if(arr[i][j]!=k&&k!=16)
                break;
            if(j<4)
                break;
        }
        if(j<4)
            return 0;
        return 1;
    }
void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    printf("");
}
int readEnterkey()
{
    char c;
    c=_getch();
    if(c==-32)
        c=_getch();
    return c;
}
int shiftup(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
            break;
    }
    if(i==3)
    return 0;
    swap(&arr[i][j],&arr[i+1][j]);
    return 1;


}
int shiftright(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
            break;
    }
    if(j==0)
        return 0;
    swap(&arr[i][j],&arr[i][j-1]);
    return 1;
}
int shiftdown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        if(arr[i][j]==0)
            break;
        if(j<4)
            break;
    }
    if(i==0)
        return 0;
    swap(&arr[i][j],&arr[i-1][j]);
    return 1;
}
int shiftleft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
            break;
    }
    if(j==3)
        return 0;
    swap(&arr[i][j],&arr[i][j+1]);
    return 1;
}
void gameRule(int arr[][4])
{
    system("cls");

    int i,j,k=1;
    printf("\t\t  MATRIX PIZZLE \n");
    printf("\n");
    printf(ANSI_COLOR_RED"      RULE OF THIS GAME \n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED"\n 1.You can only 1 step at a time with the arrow key:"ANSI_COLOR_RESET);
    printf("\n Move up  : by up arrow key");
    printf("\n Move Down: by Down arrow key");
    printf("\n Move Left: by left arrow key");
    printf("\n Move Right:by Right arrow key");
    printf(ANSI_COLOR_RED"\n 2.You can move number at empty position only"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED"\n \n\n 3.For each valid move : your total number of move will decreased by 1"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED"\n\n Wining situation : number in a 4*4 matrix should be in order from 1 to 15"ANSI_COLOR_RESET);
    printf("\n\n\n \t\t Wining situation:   \n");
    printf(ANSI_COLOR_YELLOW"-----------------------\n"ANSI_COLOR_RESET);
    for(i=0;i<4;i++)
    {
        printf(ANSI_COLOR_YELLOW" | "ANSI_COLOR_RESET);
        for(j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
                printf(ANSI_COLOR_YELLOW" %2d |"ANSI_COLOR_RESET,4*i+j+1);
                else
                    printf(ANSI_COLOR_YELLOW"    | "ANSI_COLOR_RESET);
        }
        printf("\n");
        }
        printf(ANSI_COLOR_YELLOW"-----------------------\n"ANSI_COLOR_RESET);
        printf("\n 5. You can exit the game at time by pressing 'E'or 'e'");
        printf("\n so try to win in minium no of move\n");
        printf("\n Enter any key to start.......");
        int  x=readEnterkey();
    }
    int main()
    {
        int arr[4][4];
        int maxTry=200;
        char name[20];
        for(int k=0;k<3;k++)
            printf("\n");

        printf("Player name:");
        scanf("%s",name);

        system("cls");
        while(1)
        {
            creatmatrix(arr);
            gameRule(arr);
            while(!winner(arr))
            {
                system("cls");
                if(!maxTry)
                    break;
                printf("\n\n Player name: %s,           move remaining :%d\n\n",name,maxTry);
                showmatrix(arr);
                int key=readEnterkey();
                switch(key)
                {
                case 101:
                case 69:
                    printf("\a\a\a\a\a\n Thanks for playing !\n\a");
                    printf("\n Hit 'Enter' to exit the game \n");
                    key=readEnterkey();
                    return 0;
                case 72:
                    if(shiftup(arr))
                        maxTry--;
                    break;
                case 80:
                    if(shiftdown(arr))
                        maxTry--;
                    break;
                case 77:
                    if(shiftright(arr))
                        maxTry--;
                    break;
                case 75:
                    if(shiftleft(arr))
                        maxTry--;
                    break;
                default:
                    printf("\n\n \a\a Not allowed \a");

                }
            }
            if(!maxTry)
                printf(ANSI_COLOR_RED"\n\a You loss !\a\a\n"ANSI_COLOR_RESET);
            else
                printf(ANSI_COLOR_GREEN"\n\a !!!!!!!!congratulation %s for winning This game !!!\n\a"ANSI_COLOR_RESET,name);
            fflush(stdin);
            char check;
            printf(ANSI_COLOR_GREEN"\n want to play again ? \n"ANSI_COLOR_RESET);
            printf("Enter 'Y' to play again :");
            scanf("%c",&check);
            if((check !='Y')&&(check!='y'))
                break;
            maxTry=4;
        }
        return 0;
    }
