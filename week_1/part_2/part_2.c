#include <stdio.h>

int main(void)
{
    float w1, w2, w3;
    float p1, p2, p3;

    printf("Weight 1: ");
    scanf("%f", &w1);
    
    printf("Price 1: ");
    scanf("%f", &p1);

    printf("Weight 2: ");
    scanf("%f", &w2);

    printf("Price 2: ");
    scanf("%f", &p2);

    printf("Weight 3: ");
    scanf("%f", &w3);

    printf("Price 3: ");
    scanf("%f", &p3);

    float w = w1 + w2 + w3;
    float p = w1 * p1 + w2 * p2 + w3 * p3;

    printf("Total Weight: %f\nTotal Price: %f\n", w, p);
}