#include <stdio.h>

int main(void)
{
    int a = 12;
    int b = 4;
    int c = 3;
    int d = 8;
    int e = 2;
    int f = 17;
    int g = 5;
    int h = 6;
    int i = 2;

    int z = (a + b * c - d)/e + (f % g) - h * i;

    printf("z = %i\n", z);
}