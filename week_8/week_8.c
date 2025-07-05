#include <stdio.h>
#include <string.h>

void reverseString(char str[]);
void compressString(const char* str, char* result);
void removeDuplicates(const char* str);

int main(void)
{
    char str[100], res[100], c;
    int i;

    printf("1. Reverse\n2. Compress\n3. Remove Duplicates\n");

    printf("Choice: ");
    scanf("%d", &i);

    while ((c = getchar()) != '\n');

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    int len = strlen(str);

    str[len - 1] = '\0';

    switch (i)
    {
        case 1:
            reverseString(str);
            break;

        case 2:
            compressString(str, res);
            break;

        case 3:
            removeDuplicates(str);
            break;
    
        default:
            printf("Invalid input.\n");
            break;
    }
}

void reverseString(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);
}

void compressString(const char* str, char* result)
{
    int count = 1;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0)
        {
            result[j++] = str[i];
            continue;
        }

        if (str[i] == str[i - 1])
        {
            count++;
            continue;
        }

        if (count != 1)
        {
            result[j++] = count + '0';
        }
        result[j++] = str[i];
        count = 1;
    }
    
    if (count > 0)
    {
        if (count != 1)
        {
            result[j++] = count + '0';
        }
    }
    
    result[j] = '\0';
    
    printf("Compressed string: %s\n", result);
}
void removeDuplicates(const char* str)
{
    int alpha[255];

    int len = strlen(str);

    for (int i = 0; i < 255; i++)
    {
        alpha[i] = 1;
    }

    for (int i = 0; i < len; i++)
    {
        if (alpha[str[i]])
        {
            printf("%c", str[i]);
            alpha[str[i]] = 0;
        }
    }
    printf("\n");
}