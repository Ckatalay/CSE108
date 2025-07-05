#include <stdio.h>

int fact(int n);
int binomialCoeff(int n, int k);

int main(void)
{
    int row;

    printf("Enter number of rows: ");
    scanf("%d", &row);

    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < row; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}

int fact(int n)
{
    int product = 1;

    for (int i = 2; i <= n; i++)
    {
        product *= i;
    }

    return product;
}

int binomialCoeff(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}