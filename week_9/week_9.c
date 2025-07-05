#include <stdio.h>

void print_digits(int n);
int binaryToDecimal(int n, int power);
void pattern_search(char text[], char pattern[]);

int rec_pow(int n, int powr, int initial);
int is_valid_binary(int n);

int main(void)
{
    int c, n, temp;
    char text[100];
    char pattern[100];

    printf("1. Digits\n2. Binary to Decimal\n3. Pattern Search\nChoice: ");

    if (scanf("%d", &c) != 1 || c < 1 || c > 3)
    {
        printf("Invalid input.\n");
    }

    while ((temp = getchar()) != '\n');

    switch (c)
    {
    case 1:
        printf("Number: ");

        if (scanf("%d", &n) != 1 || n < 0)
        {
           printf("Invalid input.\n");
        }
        if (n == 0)
        {
            printf("0\n");
        }
        print_digits(n);
        printf("\n");
        break;

    case 2:
        printf("Binary number: ");

        if (scanf("%d", &n) != 1 || !is_valid_binary(n))
        {
           printf("Invalid input.\n");
           break;
        }
        printf("Decimal number: %d\n", binaryToDecimal(n, 0));
        break;

    case 3:
        printf("Text: ");

        fgets(text, 98, stdin);
        for (int i = 0; i < 100; i++)
        {
            if (text[i] == '\n')
            {
                text[i] = '\0';
            }
        }

        printf("Pattern: ");

        fgets(pattern, 98, stdin);
        for (int i = 0; i < 100; i++)
        {
            if (pattern[i] == '\n')
            {
                pattern[i] = '\0';
            }
        }

        pattern_search(text, pattern);
        printf("\n");
        break;
    
    default:
        break;
    }
}

void print_digits(int n)
{
    if (n == 0)
    {
        return;
    }

    print_digits(n / 10);
    printf("%d ", n % 10);
}

int binaryToDecimal(int n, int power)
{
    if (n == 0)
    {
        return 0;
    }
    int new = power + 1;

    return rec_pow(2, power, 2) * (n % 10) + binaryToDecimal(n / 10, new);
}

int rec_pow(int n, int powr, int initial)
{
    if (n == initial && powr == 0)
    {
        return 1;
    }

    if (--powr <= 0)
    {
        return n;
    }

    return rec_pow(n * initial, powr, initial);
}

int is_valid_binary(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    if (n % 10 > 1 || n % 10 < 0)
    {
        return 0;
    }

    return is_valid_binary(n % 10);
}

void pattern_search(char text[], char pattern[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        int found = 1;

        for (int j = 0; pattern[j] != '\0'; j++)
        {
            if (text[i + j] == pattern[j])
            {
                continue;
            }
            found = 0;
        }

        if (found)
        {
            printf("Pattern found at index %d,", i);
        }
    }
}