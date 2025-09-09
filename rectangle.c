#include <stdio.h>

int main() {
    int l, b, a, p;
    printf("Enter the value of length and breadth: ");
    scanf("%d %d", &l, &b);

    a = l * b;
    p = 2 * (l + b);

    printf("Area = %d and Perimeter = %d\n", a, p);
    return 0;
}

