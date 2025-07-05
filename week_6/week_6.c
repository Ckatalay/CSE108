#include <stdio.h>
#include <math.h>

#define SIZE 10
#define SIZE_STD 5

float applyFunction(int arr[], float foo(int n[]));
float findRepetitions(int arr[]);
float findMean(int arr[]);
float countEvens(int arr[]);
float calculateStd(int arr[]);

int main(void)
{
    int arr[SIZE];

    printf("Enter %d numbers: ", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (scanf("%d", &arr[i]))
        {
            continue;
        }
        else
        {
            printf("Invalid input.\n");
            return 1;
        }
    }


    float (*ptr)(int[]) = findRepetitions;
    printf("Repetitions: %.0f\n" ,applyFunction(arr, ptr));

    ptr = findMean;
    printf("Mean: %.4f\n" ,applyFunction(arr, ptr));

    ptr = countEvens;
    printf("Even count: %.0f\n" ,applyFunction(arr, ptr));

    int std[SIZE_STD];

    printf("Enter %d numbers: ", SIZE_STD);
    for (int i = 0; i < SIZE_STD; i++)
    {
        if (scanf("%d", &std[i]))
        {
            continue;
        }
        else
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    ptr = calculateStd;

    printf("Standart Deviation: %.4f\n", applyFunction(std, ptr));
}


float applyFunction(int arr[], float foo(int n[]))
{
    return foo(arr);
}

float findRepetitions(int arr[])
{
    int last = arr[0];
    int count = 0;

    if (arr[0] == arr[1])
    {
        count++;
    }

    for (int i = 1; i < SIZE - 1; i++)
    {
        if (arr[i] == arr[i + 1] && arr[i] != arr[i - 1])
        {
            count++;
        }
    }

    return count;
}

float findMean(int arr[])
{
    float sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }

    return sum / (float)SIZE;
}

float countEvens(int arr[])
{
    int count = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }

    return count;
}

float calculateStd(int arr[])
{
    float sum = 0;
    float std = 0;

    for (int i = 0; i < SIZE_STD; i++)
    {
        sum += arr[i];
    }

    float mean = sum / (float)SIZE_STD;

    for (int i = 0; i < SIZE_STD; i++)
    {
        std += pow(arr[i] - mean, 2);
    }

    std /= (float)SIZE_STD;
    std = sqrt(std);

    return std;
}