#include <stdio.h>

int isPerfect(int num);
void printPerfect(int start, int end);

int main(void)
{
    int begin, stop;
    printf("Enter start and end: ");
    if (scanf("%d %d", &begin, &stop) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (begin < 0 || stop < 0)
    {
        printf("Start and end cannot be negative.\n");
        return 2;
    }
    if (begin > stop)
    {
        printf("Start cannot be greater than end.\n");
        return 3;
    }

    printPerfect(begin, stop);
}

int isPerfect(int num)
{
    int sum = 0;

    for (int i = num / 2; i > 0; i--)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    return num == sum;
}

void printPerfect(int start, int end)
{
    printf("Perfect numbers between %d and %d are:\n", start, end);

    for (int i = start; i <= end; i++)
    {
        if (isPerfect(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}