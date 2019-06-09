#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 100

void newTask();
void showTasks();
void deleteTask();
void save();
void load();

int main()
{
    char name[MAX];
    printf("Enter your name:\n> ");
    fgets(name, MAX, stdin);
    int c = 0;
    //omitting new line
    while(name[c] != 0)
        c++;
    name[c-1] = 0;

    printf("Welcome %s!\n", name);
    //menu
    while(1)
    {
        int selection;
        printf("[1] new task\n[2] show tasks\n[3] delete task\n[4] save\n[5] load\n[6] quit\n> ");
        scanf("%d", &selection);
        if(selection == 6)
            break;
        switch(selection)
        {
        case 1:
            newTask();
            break;
        case 2:
            showTasks();
            break;
        case 3:
            deleteTask();
            break;
        case 4:
            save();
            break;
        case 5:
            load();
            break;
        default:
            printf("Enter a number between 1 and 6\n");
        }
    }
    printf("Bye %s", name);
    getch();
    return 0;
}

void newTask()
{

}

void showTasks()
{

}

void deleteTask()
{

}

void save()
{

}

void load()
{

}
