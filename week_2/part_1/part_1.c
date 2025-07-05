#include <stdio.h>

int main(void)
{
    int s1, s2, s3;

    printf("Please input side lengths: ");
    scanf("%d %d %d", &s1, &s2, &s3);

    if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1 && s1 > 0 && s2 > 0 && s3 > 0)
    {
        printf("Valid Triangle\n");
    }
    else
    {
        printf("Invalid Triangle\n");
    }
}
