#include <stdio.h>

int main(void)
{
    int num;
    int sum = 0;
    FILE *nums = fopen("numbers.txt", "r");

    while(fscanf(nums, "%d", &num) == 1)
    {
        if (num % 2 == 0)
        {
            sum += num;
        }
    }
    fclose(nums);
    
    printf("Sum of even numbers: %d\n", sum);
}