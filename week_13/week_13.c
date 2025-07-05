#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIMPLE 1
#define DOUBLE 2

char *create_stack(int n, int *top, int *max);
void push(char **str, char *insert, int *top, int *max, int mod);
char *undo(char *str, int *top, int *max, int mod, int *done);
void print_stack(char *str, int *top, int *max, int mod);

int main(void)
{
    int top, max, i, done;
    printf("Initial size: ");
    scanf("%d", &i);
    char *str = create_stack(i, &top, &max);
    char *word = create_stack(i, &top, &max);

    printf("Choose mod:\n1. SIMPLE\n2. DOUBLE\nChoice: ");
    scanf("%d", &i);

    while (word[0] != '0')
    {
        printf("Word(0 to exit, 1 to pop): ");
        scanf("%s", word);
        if (word[0] == '1' && top != -1)
        {
            printf("Popped %s from stack\n", undo(str, &top, &max, i, &done));
            continue;
        }
        push(&str, word, &top, &max, i);
    }
    undo(str, &top, &max, i, &done);

    print_stack(str, &top, &max, i);

    free(str);
}

char *create_stack(int n, int *top, int *max)
{
    char *str = malloc(sizeof(char) * n);
    *top = -1;
    *max = n;
    return str;
}

void push(char **str, char *insert, int *top, int *max, int mod)
{
    for (int i = 0; insert[i] != '\0'; i++)
    {
        if (mod == SIMPLE)
        {
            if (*top + 1 >= *max)
            {
                *str = realloc(*str, sizeof(char) * (++(*max)));
                printf("Reallocted memory, new size: %d\n", *max);
            }
        }
        else if (mod == DOUBLE)
        {
            if (*top + 1 >= *max)
            {
                *max *= 2;
                *str = realloc(*str, sizeof(char) * *max);
                printf("Reallocted memory, new size: %d\n", *max);
            }
        }

        (*str)[++(*top)] = insert[i];
    }
    
    if (*top + 1 >= *max)
    {
        if (mod == SIMPLE)
        {
            *str = realloc(*str, sizeof(char) * (++(*max)));
            printf("Reallocted memory, new size: %d\n", *max);
        }
        else if (mod == DOUBLE)
        {
            *max *= 2;
            *str = realloc(*str, sizeof(char) * *max);
            printf("Reallocted memory, new size: %d\n", *max);
        }
    }
    (*str)[++(*top)] = ' ';
}

char *undo(char *str, int *top, int *max, int mod, int *done)
{
    *done = 0;
    char *word = malloc(sizeof(char) * (*top + 1));
    int i;
    int j = 0;
    for (i = *top - 1; str[i] != ' '; i--)
    {
        word[j++] = str[i];
        if ((--(*top)) == -1)
        {
            printf("WARNING: STACK IS EMPTY.\n");
            *done = 1;
            break;
        }
    }
    if (*top != -1)
    {
        (--(*top));
    }

    int len = strlen(word);
    char temp;


    for (int j = 0; j < len / 2; j++)
    {
        temp = word[j];
        word[j] = word[len - j - 1];
        word[len - j - 1] = temp;
    }

    if (mod == DOUBLE && *top != -1)
    {
        if (i < *max / 2)
        {
            *max /= 2;
            str = realloc(str, sizeof(char) * *max);
            printf("Reallocted memory, new size: %d\n", *max);
        }
    }
    return word;
}

void print_stack(char *str, int *top, int *max, int mod)
{
    int done = 0;
    char *word;
    if (*top == -1)
    {
        return;
    }
    while(!done)
    {
        word = undo(str, top, max, mod, &done);
        if (done)
        {
            break;
        }
        printf("%s\n", word);
        free(word);
    }
    printf("%s\n", word);
    free(word);
}