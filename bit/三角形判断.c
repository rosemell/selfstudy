#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s

#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            {

                printf("Equilateral triangle!\n");
            }
        }
        else if (a == b || b == c || a == c) {
            {
                printf("Isosceles triangle!\n");

            }

        }
        else {
            printf("Ordinary triangle!");
        }
    }
    else {
        printf("Not a triangle!");
    }

    return 0;
}