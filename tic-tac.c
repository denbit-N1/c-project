#include<stdio.h>
int check_win(char arr[3][3], char symbol, char *name)
{
    int rowcount=0,colcount=0,diacount=0,dia2count=0,i,j;

    for ( i = 0; i < 3; i++)
    {
        rowcount=0;
        colcount=0;
        for ( j = 0; j < 3; j++)
        {
            if (arr[i][j]==symbol)
            {
                rowcount++;
            }
            if (arr[j][i]==symbol)
            {
                colcount++;
            }
        }
        if (rowcount == 3 || colcount == 3)
        {
            printf("%s win this Game.\n",name);
            printf("Thank you for playing.");
            return 0;
        }
        if (arr[i][i]==symbol)
        {
            diacount++;
        }
        if (arr[i][2-i]==symbol)
        {
            dia2count++;
        }
        
    }   
    if (diacount == 3 || dia2count == 3)
    {
        printf("%s win this Game\n",name);
        printf("Thank you for playing.");
        return 0;
    }
    return 1;
}


int set_array(char arr[3][3], int i, int j, char sumbol,int turn)
{
    if (arr[i][j] == '*')
        arr[i][j]=sumbol;
    else
        printf("Wrong position Try again\n",turn--);
    return turn;
}


void print_array(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ",arr[i][j]);
            if (j<2)
                printf("|");
            
        }
        printf("\n");
        if (i<2)
            printf("----------\n");
    }
    
}


int main()
{
    int turn=0,row,col,m;
    char arr[3][3]={{'*','*','*'},{'*','*','*'},{'*','*','*'}};
    char p1[20],p2[20],sp1,sp2;
    printf("\n------WELCOME TO MY TIC-TAC GAME------\n\n");
    printf("Player one enter your name : ");
    scanf("%s",&p1);
    printf("Player two enter your name : ");
    scanf("%s",&p2);
    print_array(arr);
    sp1='X';
    sp2='O';
    printf("\nSymbol for player one '%c'\n",sp1);
    printf("Symbol for player two '%c'\n",sp2);
    do
    {
        if (turn%2 == 0)
        {
            printf("\n%s it's your turn :-\n",p1);
            printf("Enter your position : ");
            scanf("%d %d",&row,&col);
            turn = set_array(arr, row, col, sp1, turn);
            print_array(arr);
            m = check_win(arr, sp1, p1);
            if (m==0)
                break;
            turn++;
        }
        else
        {
            printf("\n%s it's your turn :-\n",p2);
            printf("Enter your position : ");
            scanf("%d %d",&row,&col);
            turn = set_array(arr, row, col, sp2, turn);
            print_array(arr);
            m = check_win(arr, sp2, p2);
            if (m==0)
                break;
            turn++;
        }
    }while(turn!=9);
}