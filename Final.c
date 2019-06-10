#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 100

struct task
{
    int day;
    char taskName[MAX];
    int startTime;
    int endTime;
    struct task * next;
};
typedef struct task * node; // struct task * = node

node head;
char userName[MAX];

void newTask();
void showTasks();
void deleteTask();
void save(char name[]);
void load(char name[], int keep);
void trimEnd(char * string);
void listAdd(int day, char taskName[], int startTime, int endTime, int userSide);
void listDelete(int day, char taskName[]);
int checkTask(int day, char taskName[], int startTime, int endTime);
int timeConflict(int s1, int e1, int s2, int e2, int flag);
void cls();

int main()
{
    char name[MAX];
    int keep = 1;
    printf("Enter your name:\n> ");
    scanf("%s",name);
    strcpy(userName, name);
    printf("Welcome %s!\n", name);
    //menu
    while(1)
    {
        int selection;
        printf("\n[1] new task\n[2] delete task\n[3] show tasks\n[4] save\n[5] load\n[6] quit\n> ");
        scanf("%d", &selection);
        if(selection == 6)
            break;
        switch(selection)
        {
        case 1:
            newTask();
            break;
        case 2:
            deleteTask();
            break;
        case 3:
            cls();
            showTasks();
            break;
        case 4:
            cls();
            save(name);
            break;
        case 5:

            if(head != NULL)
            {

                printf("Keep existing data?\n[1] Yes\n[2] No\n> ");
                scanf("%d", &keep);
                while(keep < 1 || keep > 2)
                {
                    printf("Wrong number\nKeep existing data?\n[1] Yes\n[2] No\n> ");
                    scanf("%d", &keep);
                }
                if(keep == 2)
                    keep = 0;
            }
            cls();
            load(name, keep);
            break;
        default:
            cls();
            printf("Enter a number between 1 and 6\n");
        }
    }
    printf("Bye %s\n", name);
    getch();
    return 0;
}

void newTask()
{
    int day;
    printf("Enter the day:\n> ");
    scanf("%d",&day);
    while(day < 0 || day > 6)
    {
        printf("The day number should be between 0 and 6\nEnter the day:\n> ");
        scanf(" %d",&day);
    }

    char taskName[MAX];
    printf("Enter the name:\n> ");
    scanf("%s", taskName);

    int startTime;
    printf("Enter the start time:\n> ");
    scanf("%d",&startTime);
    while(startTime < 0 || startTime >= 1440)
    {
        printf("start time should be between 0 and 1439\nEnter the start time:\n> ");
        scanf("%d",&startTime);
    }


    int endTime;
    printf("Enter the end time:\n> ");
    scanf("%d",&endTime);
    while(endTime < 1 || endTime > 1440 || endTime <= startTime)
    {
        if(endTime <= startTime)
            printf("end time should be greater than start time\n");
        else
            printf("start time should be between 1 and 1440\n");
        printf("Enter the end time:\n> ");
        scanf("%d",&endTime);
    }
    //creating
    cls();
    listAdd(day, taskName, startTime, endTime, 1);
}

void showTasks()
{
    node node = head;

    int flag = 0;
    printf("0 (Saturday): ");
    while(node != NULL)
    {
        if(node->day == 0)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");
    node = head;
    flag = 0;
    printf("1 (Sunday): ");
    while(node != NULL)
    {
        if(node->day == 1)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");
    node = head;
    flag = 0;
    printf("2 (Monday): ");
    while(node != NULL)
    {
        if(node->day == 2)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");
    node = head;
    flag = 0;
    printf("3 (Tuesday): ");
    while(node != NULL)
    {
        if(node->day == 3)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");
    node = head;
    flag = 0;
    printf("4 (Wednesday): ");
    while(node != NULL)
    {
        if(node->day == 4)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");
    node = head;
    flag = 0;
    printf("5 (Thursday): ");
    while(node != NULL)
    {
        if(node->day == 5)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");
    node = head;
    flag = 0;
    printf("6 (Friday): ");
    while(node != NULL)
    {
        if(node->day == 6)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");
}

void deleteTask()
{
    int day;
    printf("Enter the day:\n> ");
    scanf("%d",&day);
    while(day < 0 || day > 6)
    {
        printf("The day number should be between 0 and 6\nEnter the day:\n> ");
        scanf("%d",&day);
    }

    char taskName[MAX];
    printf("Enter the name:\n> ");
    scanf("%s", taskName);

    //deleting
    cls();
    listDelete(day, taskName);
}

void save(char name[])
{

    FILE * userData;
    char nameCopy[MAX];
    strcpy(nameCopy, name);
    if(userData = fopen(strcat(nameCopy,".txt"), "w"))
    {
        node node = head;
        while(node != NULL)
        {
            fprintf(userData, "data: %d %s %d %d\n", node->day, node->taskName, node->startTime, node->endTime);
            node = node->next;
        }
        fclose(userData);
        printf("Saved successfully\n");
    }
    else
    {
        printf("An error has occurred! Could not save data\n");
    }
}

void load(char name[], int keep)
{
    FILE * userData;
    char nameCopy[MAX];
    strcpy(nameCopy, name);
    if(userData = fopen(strcat(nameCopy,".txt"), "r"))
    {
        if(keep == 0)
        {
            free(head);
            head = NULL;
        }
        int day;
        char taskName[MAX];
        int startTime;
        int endTime;
        int returnNumber;
        while( (returnNumber = fscanf(userData, "data: %d %s %d %d\n", &day, taskName, &startTime, &endTime) ) > 0)
        {
            if(returnNumber < 4) //corrupted line
            {
                printf("Warning: some data in save file is corrupted\n", ftell(userData));
                //return to first of line
                char c;
                while( (c = getc(userData) ) != '\r') //first of file or first of line
                {
                    fseek(userData, -2, SEEK_CUR);
                    if(c == '\n')
                        {getc(userData);break;}
                }
                continue;
            }
            listAdd(day, taskName, startTime, endTime, 0);
        }
        fclose(userData);
        printf("Loaded successfully\n");
    }
    else
    {
        printf("The save file could not be found\n");
    }
}

void listAdd(int day, char taskName[], int startTime, int endTime, int userSide)
{
    //checking task
    int flag = 0;
    switch(checkTask(day, taskName, startTime, endTime))
    {
        case 1:
            flag = 1;
            if(userSide)
            {
                printf("Conflict with name. The name \'%s\' already exists in that day\n", taskName);
            }
            break;
        case 2:
            flag = 1;
            if(userSide)
            {
                printf("Conflict with time schedule\n");
            }

            break;
    }
    if(flag == 1)
        return;
    //creating task
    node new_task;
    new_task = (node) malloc(sizeof(struct task));
    new_task->day = day;
    strcpy(new_task->taskName,taskName);
    new_task->startTime = startTime;
    new_task->endTime = endTime;
    new_task->next = NULL;

    if(head == NULL)
    {
        head = new_task;
    }
    else
    {
        //adding to the sorted position
        int flag = 0;
        node node = head;
        if(node->next == NULL)
        {
            if(node->day == day && startTime < node->startTime)
            {
                new_task->next = head;
                head = new_task;
            }
            else
            {
                node->next = new_task;
            }
            flag = 1;
        }
        else while(node->next != NULL)
        {
            if(day == node->next->day && startTime < node->next->startTime)
            {
                new_task->next = node->next;
                node->next = new_task;
                flag = 1;
                break;
            }
            node = node->next;
        }
        if(flag == 0) //not assigned yet
        {
            node->next = new_task;
        }
        /*
        while(node->next != NULL)
            node = node->next;
        node->next = new_task;
        */
    }
    if(userSide)
    {
        printf("There is no error and the new task is created\n");
    }
}

void listDelete(int day, char taskName[])
{
    //deleting task
    if(head != NULL)
    {
        node tmp_node = head;
        node node = head;
        //checking first node exclusively (because of the tmp_node system which provides prev-next compatibility)
        if(day == node->day && strcmp(taskName, node->taskName) == 0)
        {
            if(node->next == NULL)
                {
                    free(head);
                    head = NULL;
                }
            else
                {
                    head = node->next;
                }
            printf("There is no error and the task is deleted\n");
            return;
        }

        while(node->next != NULL)
        {
            node = node->next;
            if(day == node->day && strcmp(taskName, node->taskName) == 0)
            {
                if(node->next == NULL)
                    tmp_node->next = NULL;
                else
                    tmp_node->next = node->next;
                printf("There is no error and the task is deleted\n");
                return;
            }
            tmp_node = tmp_node->next;
        }
    }
    else
    {
        printf("No tasks yet\n");
        return;
    }
    printf("The task \"%s\" in that day was not found\n", taskName);
}

///return 0 if new task does not have any conflict with prev tasks
///return 1 for name exists
///return 2 for time conflict
int checkTask(int day, char taskName[], int startTime, int endTime)
{
    if(head == NULL)
        return 0;
    node node = head;
    while(node != NULL)
    {
        if(node->day == day)
        {
            if(strcmp(node->taskName, taskName) == 0)
                return 1;
            if(timeConflict(startTime, endTime, node->startTime, node->endTime, 0))
                return 2;
        }
        //iterator
        node = node->next;
    }
    return 0;
}

int timeConflict(int s1, int e1, int s2, int e2, int flag)
{
    if(s2 >= s1 && s2 < e1)
        return 1;
    if(e2 > s1 && e2 <= s1)
        return 1;
    //swap 1 and 2 to check:
    if(flag == 0 && timeConflict(s2, e2, s1, e1, 1) )
        return 1;
    return 0;
}

void cls()
{
    system("cls");
    printf("User: %s\n\n", userName);
}
