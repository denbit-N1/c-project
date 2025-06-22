#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int user_no = -1;
struct user
{
    char username[20];
    char password[18];
}user[10];

void user_register()
{
    user_no++;
    FILE *un, *ps;
    char ch,ch2,arr[10][20],arr2[10][18];
    int col=0;
    un=fopen("username.txt","a+");
    ps=fopen("password.txt","a+");
    while (1)
    {
        ch = fgetc(un);
        if (ch==EOF)
            break;
        if (ch=='\n')
        {
            arr[user_no][col]='\0';
            strcpy(user[user_no].username, arr[user_no]);
            user_no++;
            col = 0;
        }
        else
        {
            arr[user_no][col]=ch;
            col++;
        } 
    }
    user_no=0;
    while (1)
    {
        ch2 = fgetc(ps);
        if (ch2==EOF)
            break;
        if (ch2=='\n')
        {
            arr2[user_no][col]='\0';
            strcpy(user[user_no].password, arr2[user_no]);
            user_no++;
            col = 0;
        }
        else
        {
            arr2[user_no][col]=ch2;
            col++;
        } 
    }
    printf("Enter your username : ");
    scanf("%s",user[user_no].username);
    fprintf(un,"%s",user[user_no].username);
    fputs("\n",un);
    printf("Enter your password : ");
    scanf("%s",user[user_no].password);
    fprintf(ps,"%s",user[user_no].password);
    fputs("\n",ps);
    fclose(un);
    fclose(ps);
    printf("Registration successful!\n");
}
void user_login()
{
    char username[20],password[18];
    printf("Enter username : ");
    scanf("%s",username);
    printf("Enter password : ");
    scanf("%s",password);
    if (strcmp(user[user_no].username,username)==0 && strcmp(user[user_no].password,password)==0)
    {
        printf("Login successful! Welcome, %s!\n",username);
    }
    else
    {
        printf("Login failed! Incorrect username or password\n");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Register\n2. Login\n3. Exit\nSelect your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            user_register();
            break;
        case 2:
            user_login();
            break;
        case 3:
            printf("\nExit succcessful!\n");
            return 0;
        default:
            printf("Invalid choise, selece correct option.\n");
            break;
        }
    }
}