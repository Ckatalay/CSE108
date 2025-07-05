#include <stdio.h>

int isPrime(int num);
void printPrime(int start, int end);

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

    printPrime(begin, stop);
}

int isPrime(int num)
{
    if (num == 1)
    {
        return 0;
    }

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void printPrime(int start, int end)
{
    printf("Prime numbers between %d and %d are:\n", start, end);

    for (int i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}