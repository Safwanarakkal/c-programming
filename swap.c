#include <stdio.h>

int main() {
    int a,b,temp;
    a=5;
    b=6;
    temp=a;
    a=b;
    b=temp;
    printf("Swapped number are a=%d b=%d",a,b);
    return 0;
}

