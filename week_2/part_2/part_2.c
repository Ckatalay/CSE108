#include <stdio.h>

int main(void)
{
    float consume;
    float bill = 0;

    printf("Enter the units of consumed: ");
    scanf("%f", &consume);

    if (consume < 0)
    {
        printf("Consumption cannot be negative.\n");
        return 1;
    }

    if (consume > 250)
    {
        bill += (consume - 250) * 1.5;
        consume = 250;
    }
    if (consume > 100)
    {
        bill += (consume - 100) * 1.2;
        consume = 100;
    }
    if (consume > 50)
    {
        bill += (consume - 50) * 0.75;
        consume = 50;
    }
    if (consume > 0)
    {
        bill += consume * 0.5;
        consume = 0;
    }

    printf("Net amount to be paid: %.0f\n", bill * 1.2);
}
