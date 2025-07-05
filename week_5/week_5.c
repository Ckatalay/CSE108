#include <stdio.h>

int generateCollatzSequence(int start, int lenght, FILE *file);
void convertToBinary(int n, FILE *file);
void convertToHex(int n, FILE *file);
void convertToOctal(int n, FILE *file);

int main(void)
{
    int start, n;

    printf("Enter the starting number of the Colatz Sequence: ");
    if(scanf("%d", &start) != 1 || start <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter how many terms to generate: ");
    if(scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    FILE *file = fopen("collatz.txt", "w");

    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    int num = generateCollatzSequence(start, n, file);
    if(!num)
    {
        return 1;
    }

    fprintf(file, "%d\n", num);

    file = fopen("collatz.txt", "a");

    printf("Last number in sequence: %d\n", num);
    int c;
    printf("Choose a conversion:\n");
    printf("1. Decimal to binary\n");
    printf("2. Decimal to hexadecimal\n");
    printf("3. Decimal to octal\n");
    printf("Your choice: ");

    if (scanf("%d", &c) != 1 || c > 3 || c < 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    switch (c)
    {
    case 1:
        convertToBinary(num, file);
        break;

    case 2:
        convertToHex(num, file);
        break;
    
    case 3:
        convertToOctal(num, file);

    default:
        break;
    }
}

int generateCollatzSequence(int start, int lenght, FILE *file)
{
    int num = start;
    if (num <= 0)
    {
        printf("Invalid input, input values greater than 0.\n");
        return 0;
    }

    printf("%d\n", start);
    fprintf(file, "%d\n", start);
    lenght--;

    while (num > 0 && lenght > 0)
    {
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num = num * 3 + 1;
        }
        printf("%d\n", num);
        fprintf(file, "%d\n", num);
        lenght--;
    }
    return num;
}

void convertToBinary(int n, FILE *file)
{
    printf("Decimal: %d\n", n);
    fprintf(file, "Decimal: %d\n", n);
    printf("Decimal to hexadecimal conversion: ");
    fprintf(file, "Decimal to hexadecimal conversion: ");

    if (n == 0)
    {
        printf("0\n");
        fprintf(file, "0\n");
        return;
    }

    int binary[32];
    int i = 0;

    while (n > 0)
    {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
        fprintf(file, "%d", binary[j]);
    }
    printf("\n");
}

void convertToHex(int n, FILE *file)
{
    printf("Decimal: %d\n", n);
    fprintf(file, "Decimal: %d\n", n);
    printf("Decimal to hexadecimal conversion: ");
    fprintf(file, "Decimal to hexadecimal conversion: ");

    if (n == 0)
    {
        printf("0\n");
        fprintf(file, "0\n");
        return;
    }

    int hex[32];
    int i = 0;

    while (n > 0)
    {
        hex[i] = n % 16;
        n /= 16;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        switch (hex[j])
        {
        case 10:
            printf("A");
            fprintf(file, "A");
            break;

        case 11:
            printf("B");
            fprintf(file, "B");
            break;

        case 12:
            printf("C");
            fprintf(file, "C");
            break;

        case 13:
            printf("D");
            fprintf(file, "D");
            break;

        case 14:
            printf("E");
            fprintf(file, "E");
            break;

        case 15:
            printf("F");
            fprintf(file, "F");
            break;
        
        default:
            printf("%d", hex[j]);
            fprintf(file, "%d", hex[j]);
            break;
        }
    }
    printf("\n");
}

void convertToOctal(int n, FILE *file)
{
    printf("Decimal: %d\n", n);
    fprintf(file, "Decimal: %d\n", n);
    printf("Decimal to hexadecimal conversion: ");
    fprintf(file, "Decimal to hexadecimal conversion: ");

    if (n == 0)
    {
        printf("0\n");
        fprintf(file, "0\n");
        return;
    }

    int octal[32];
    int i = 0;

    while (n > 0)
    {
        octal[i] = n % 8;
        n /= 8;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
        fprintf(file, "%d", octal[j]);
    }
    printf("\n");
}