#include <stdio.h>

int main() {
    int a;
    printf("Enter the value: ");
    scanf("%d", &a);
    if(a%2==0)
    {
     printf("Given number is even");
    }
    else
    {
     printf("Given number is odd");
    }
    return 0;
}

