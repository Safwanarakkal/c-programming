#include <stdio.h>
#include <stdlib.h>

void insertion();
void deletion();
void searching();
void sorting();
void display();

int array[100];
int num;
int n;

int main() {
    int i;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter the array elements:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }

    printf("The array elements are:\n");
    for (i = 0; i < num; i++) {
        printf("%d\n", array[i]);
    }

    while (1) {
        printf("\nEnter an option:\n");
        printf("1. Insertion\n2. Deletion\n3. Searching\n4. Sorting\n5. Display\n6. Exit\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                searching();
                break;
            case 4:
                sorting();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}

void insertion() {
    int number, i;
    printf("Enter the number to be inserted:\n");
    scanf("%d", &number);
    array[num] = number;
    num++;
    printf("The array elements are:\n");
    for (i = 0; i < num; i++) {
        printf("%d\n", array[i]);
    }
}

void deletion() {
    int ind, j;

    if (num > 0) {
        printf("\nEnter the index of element to delete (0 to %d):\n", num - 1);
        scanf("%d", &ind);

        if (ind < 0 || ind >= num) {
            printf("Invalid index.\n");
            return;
        }

        for (j = ind; j < num - 1; j++) {
            array[j] = array[j + 1];
        }

        num--;
    } else {
        printf("\nArray is empty\n");
    }

    printf("The array elements are:\n");
    for (int i = 0; i < num; i++) {
        printf("%d\n", array[i]);
    }
}

void searching() {
    int to_search, found = 0, i;
    printf("Enter the element to search: ");
    scanf("%d", &to_search);

    for (i = 0; i < num; i++) {
        if (array[i] == to_search) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("%d is found at position %d\n", to_search, i + 1);
    } else {
        printf("%d is not found in the array\n", to_search);
    }
}

void sorting() {
    int i, j, a;

    for (i = 0; i < num - 1; i++) {
        for (j = i + 1; j < num; j++) {
            if (array[i] > array[j]) {
                a = array[i];
                array[i] = array[j];
                array[j] = a;
            }
        }
    }

    printf("The numbers arranged in ascending order are:\n");
    for (i = 0; i < num; i++) {
        printf("%d\n", array[i]);
    }
}

void display() {
    printf("The array elements are:\n");
    for (int i = 0; i < num; i++) {
        printf("%d\n", array[i]);
    }
}

