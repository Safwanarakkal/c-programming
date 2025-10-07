#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int q[SIZE];
int rear = 0, front = 0;

void insertq(int item)
{
    int r1 = (rear + 1) % SIZE;
    if (r1 == front)
        printf("Queue is full\n");
    else
    {
        rear = r1;
        q[rear] = item;
    }
}

int deleteq1(int *status)
{
    if (front == rear)
    {
        *status = 0;
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        front = (front + 1) % SIZE;
        *status = 1;
        return q[front];
    }
}

int searchq(int item)
{
    int t;
    if (front != rear)
    {
        t = (front + 1) % SIZE;
        while (t != (rear + 1) % SIZE && q[t] != item)
            t = (t + 1) % SIZE;

        if (q[t] == item)
            return t;
        else
            return -1;
    }
    else
        return -1;
}

void main()
{
    int item, opt, ans, status;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter the Data: ");
            scanf("%d", &item);
            insertq(item);
            break;

        case 2:
            item = deleteq1(&status);
            if (status == 1)
                printf("Deleted = %d\n", item);
            break;

        case 3:
            printf("Enter the number to search: ");
            scanf("%d", &item);
            ans = searchq(item);
            if (ans == -1)
                printf("Not found\n");
            else
                printf("Item found at position %d\n", ans);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option!\n");
        }
    }
}

