#include <stdio.h>

int main(void)
{
    int year;

    printf("Enter a year: ");
    if (scanf("%d", &year) == 0)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (year < 0)
    {
        printf("Year cannot be negative.\n");
        return 2;
    }

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        printf("%d is a leap year.\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }
}