#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int new_user = -1;
struct user
{
    char username[20];
    char password[18];
}user[10];

void user_register()
{
    new_user++;
    FILE *fp;
    fp=fopen("register_data.txt","a");
    if (fp==NULL)
        exit(1);
    printf("Enter your username : ");
    scanf("%s",user[new_user].username);
    fprintf(fp,"%s",user[new_user].username);
    fputs(" ",fp);
    printf("Enter your password : ");
    scanf("%s",user[new_user].password);
    fprintf(fp,"%s",user[new_user].password);
    fputs("\n",fp);
    fclose(fp);
    printf("Registration successful!\n");
}
void user_login()
{
    char username[20],password[18];
    printf("Enter username : ");
    scanf("%s",username);
    printf("Enter password : ");
    scanf("%s",password);
    if (strcmp(user[new_user].username,username)==0 && strcmp(user[new_user].password,password)==0)
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