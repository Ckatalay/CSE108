#include <stdio.h>
#include <stdlib.h>

int get_money(void);

int main(void)
{
    printf("Money left = %d\n", get_money());
}

int get_money(void)
{
    int *prices = malloc(sizeof(int) * 100);
    int money;

    printf("Prices: ");
    int i = 0;
    while(scanf("%d", &prices[i]) == 1 && prices[i] != -1)
    {
        i++;
    }

    printf("Money: ");
    scanf("%d", &money);

    int cheapest = prices[0];
    int cheaper = cheapest;

    for (int i = 0; prices[i] != -1; i++)
    {
        int current = prices[i];
        if (current < cheapest)
        {
            cheaper = cheapest;
            cheapest = current;
        }
    }

    if (cheaper + cheapest > money)
    {
        free(prices);
        return money;
    }
    
    free(prices);

    return money - cheapest - cheaper;
}