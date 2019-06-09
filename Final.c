[TODO: fgets problem - **head problem initialize - while loop in taskShow() - save and load]

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
struct task ** head;

void newTask();
void showTasks();
void deleteTask();
void save(char name[]);
void load(char name[]);
void trimEnd(char * string);
void listAdd(int day, char taskName[], int startTime, int endTime);
void listDelete(int day, char taskName[]);
int checkTask(int day, char taskName[], int startTime, int endTime);

int main()
{
    char name[MAX];
    printf("Enter your name:\n> ");
    fgets(name, MAX, stdin);
    //omitting new line
    trimEnd(name);

    printf("Welcome %s!\n", name);
    //menu
    while(1)
    {
        int selection;
        printf("[1] new task\n[2] delete task\n[3] show tasks\n[4] save\n[5] load\n[6] quit\n> ");
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
            showTasks();
            break;
        case 4:
            save(name);
            break;
        case 5:
            load(name);
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
    fgets(taskName, MAX, stdin);
    trimEnd(taskName);

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
    listAdd(day, taskName, startTime, endTime);
}

void showTasks()
{
    if(*head == NULL)
    {
        printf("0 (Saturday):\n1 (Sunday):\n2 (Monday):\n3 (Tuesday):\n4 (Wednesday):\n5 (Thursday):\n6 (Friday):\n");
        return;
    }
    struct task * node = *head;

    int flag = 0;
    printf("0 (Saturday): ");
    while(node->next != NULL) //problem when first->next = NULL and first->day = 0
    {
        if(node->day == 0)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");

    flag = 0;
    printf("1 (Sunday): ");
    while(node->next != NULL) //problem when first->next = NULL and first->day = 1
    {
        if(node->day == 1)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");

    flag = 0;
    printf("2 (Monday): ");
    while(node->next != NULL) //problem when first->next = NULL and first->day = 2
    {
        if(node->day == 2)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");

    flag = 0;
    printf("3 (Tuesday): ");
    while(node->next != NULL) //problem when first->next = NULL and first->day = 3
    {
        if(node->day == 3)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");

    flag = 0;
    printf("4 (Wednesday): ");
    while(node->next != NULL) //problem when first->next = NULL and first->day = 4
    {
        if(node->day == 4)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");

    flag = 0;
    printf("5 (Thursday): ");
    while(node->next != NULL) //problem when first->next = NULL and first->day = 5
    {
        if(node->day == 5)
        {
            printf("%s%s (from: %d, to: %d)", flag == 0 ? "" : " -> ", node->taskName, node->startTime, node->endTime );
            flag = 1;
        }
        node = node->next;
    }
    printf("\n");

    flag = 0;
    printf("6 (Friday): ");
    while(node->next != NULL) //problem when first->next = NULL and first->day = 6
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
    fgets(taskName, MAX, stdin);
    trimEnd(taskName);

    //deleting
    listDelete(day, taskName);
}

void save(char name[])
{
    //before last thing to do
}

void load(char name[])
{
    //last thing to do
}

void listAdd(int day, char taskName[], int startTime, int endTime)
{
    //checking task
    int flag = 0;
    switch(checkTask(day, taskName, startTime, endTime))
    {
        case 1:
            flag = 1;
            printf("Conflict with name. The name \'%s\' already exists in that day\n", taskName);
            break;
        case 2:
            flag = 1;
            printf("Conflict with time schedule\n");
            break;
    }
    if(flag == 1)
        return;
    //creating task
    struct task * new_task;
    new_task = (struct task *) malloc(sizeof(struct task));
    new_task->day = day;
    strcpy(new_task->taskName,taskName);
    new_task->startTime = startTime;
    new_task->endTime = endTime;
    new_task->next = NULL;

    if(*head == NULL)
    {
        *head = new_task;
    }
    else
    {
        struct task * node = *head;
        while(node->next != NULL)
            node = node->next;
        node->next = new_task;
    }
    printf("There is no error and the new task is created\n");
}

void listDelete(int day, char taskName[])
{
    //deleting task
    if(*head != NULL)
    {
        struct task * node = *head;
        //checking first node exclusively (because of the tmp_node system which provides prev-next compatibility)
        if(day == node->day && strcmp(taskName, node->taskName) == 0)
        {
            if(node->next == NULL)
                {
                    free(*head);
                    *head = NULL;
                }
            else
                {
                    *head = node->next;
                }
            printf("There is no error and the task is deleted\n");
            return;
        }
        struct task * tmp_node = node;
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
    printf("The task \'%s\' in that day was not found\n");
}

///return 0 if new task does not have any conflict with prev tasks
///return 1 for name exists
///return 2 for time conflict
int checkTask(int day, char taskName[], int startTime, int endTime)
{
    if(*head == NULL)
        return 0;
    struct task * node = *head;
    while(node->next != NULL)
    {
        if(node->day == day)
        {
            if(strcmp(node->taskName, taskName) == 0)
                return 1;
            if(startTime > node->startTime && startTime < node->endTime)
                return 2;
            if(node->startTime > startTime &&  node->endTime < endTime)
                return 2;
        }
        //iterator
        node = node->next;
    }
    return 0;
}

///omitting new line
void trimEnd(char * string)
{
    int c = 0;
    while(string[c] != 0)
        c++;
    string[c-1] = 0;
}
