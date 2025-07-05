#include <stdio.h>

int main(void)
{
    int num;
    int rev = 0;
    int is_negative = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        num *= -1;
        is_negative = 1;
    }

    while (num != 0)
    {
        rev *= 10;
        rev += num % 10;
        num /= 10;
    }

    if (is_negative)
    {
        rev *= -1;
    }

    printf("Reversed number: %d\n", rev);
}