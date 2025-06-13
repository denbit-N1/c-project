#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int count=1,originalnum,num;
    srand(time(NULL));
    originalnum = rand()%100 + 1;
    printf("Welcome to the guessing number games\n\n");
    printf("Please enter your guess number between 1 to 100 : ");
    
    do
    {
        scanf("%d",&num);
        if (originalnum==num)
        {
            printf("\n Congratulationsc !!! You have sucessfully guessed the number in %d attempts.\nThank for playing.",count);
        }
        else
        {
            if (originalnum>num)
            {
                printf("Guess a lager number : ");
                count++;
            }
            else
            {
                printf("Guess a smaller number : ");
                count++;
            }
        }
    }while (originalnum != num);
    return 0;
}