#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    float price;
    int quantity;
} item_t;


typedef struct
{
    int capacity;
    item_t *items;
} cart_t;

cart_t create_cart(void);
item_t create_item(void);
void remove_item(cart_t cart, int *count);
int find_item(cart_t cart, int count, char *name, int print);
void print_items(cart_t cart, int count);

int main(void)
{
    cart_t cart = create_cart();
    int cap = sizeof(item_t) * cart.capacity;
    cart.items = malloc(cap);

    int count = 0;
    
    while (1)
    {
        int choice;
        printf("1. Add Item\n2. Remove Item\n3. Search Item\n4. Print Card\n5. Exit\n");

        while (1)
        {
            printf("Choice: ");
            if (scanf("%d", &choice) == 0)
            {
                printf("Invalid choice.\n");
                continue;
            }
            break;
        }

        char name[100];
        switch (choice)
        {
        case 1:
            if (count == cart.capacity)
            {
                cap *= 2;
                cart.items = realloc(cart.items, cap);
                printf("Array resized to capacity: %d\n", (int)(cap / sizeof(item_t)));
            }
            cart.items[count++] = create_item();
            break;

        case 2:
            remove_item(cart, &count);

            if (count < cart.capacity / 2)
            {
                cap /= 2;
                cart.items = realloc(cart.items, cap);
                printf("Array resized to capacity: %d\n", (int)(cap / sizeof(item_t)));
            }
            break;

        case 3:
            while (1)
            {
                printf("Name: ");
                if (scanf("%s", name) == 0)
                {
                    printf("Invalid name.\n");
                    continue;
                }
                break;
            }
            if (find_item(cart, count, name, 1) == -1)
            {
                printf("Item not found.\n");
            }

        case 4:
            print_items(cart, count);
            break;

        case 5:
            free(cart.items);
            printf("Freeing memory, Goodbye!\n");
            return 0;
        
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}

cart_t create_cart(void)
{
    cart_t cart;
    while (1)
    {
        printf("Enter initial card capacity: ");
        if (scanf("%d", &cart.capacity) == 0)
        {
            printf("Invalid capacity.\n");
            continue;
        }
        break;
    }
    return cart;
}

item_t create_item(void)
{
    item_t item;
    while (1)
    {
        char name[100];
        printf("Name: ");
        if (scanf("%s", name) == 0)
        {
            printf("Invalid name.\n");
            continue;
        }
        strcpy(item.name, name);
        break;
    }

    while (1)
    {
        printf("Price: ");
        if (scanf("%f", &item.price) == 0)
        {
            printf("Invalid name.\n");
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Quantity: ");
        if (scanf("%d", &item.quantity) == 0)
        {
            printf("Invalid name.\n");
            continue;
        }
        break;
    }

    return item;
}

void remove_item(cart_t cart, int *count)
{
    char name[100];
    while (1)
    {
        printf("Enter item name to remove: ");
        if (scanf("%s", name) == 0)
        {
            printf("Invalid name.\n");
            continue;
        }
        break;
    }

    int item = find_item(cart, *count, name, 0);

    if (item == -1)
    {
        printf("Item does not exist.\n");
        return;
    }

    *count = *count - 1;
    printf("Item removed.\n");
}

int find_item(cart_t cart, int count, char *name, int print)
{   
    for (int i = 0; i < count; i++)
    {
        if (strcmp(name, cart.items[i].name) == 0)
        {
            if (print)
            {
                float total = cart.items[i].price * cart.items[i].quantity;
                printf("----------------------------------------\n"
                    "%-10s%-10s%-10s%-10s\n----------------------------------------\n", "Name", "Price", "Quantity", "Subtotal");
                printf("%-10s%-10.2f%-10d%-10.2f\n----------------------------------------\n", cart.items[i].name, cart.items[i].price,
                                                                                            cart.items[i].quantity, total);
            
            }
            return i;
        }
    }
    return -1;
}

void print_items(cart_t cart, int count)
{
    float total = 0;
    printf("----------------------------------------\n"
    "%-10s%-10s%-10s%-10s\n----------------------------------------\n", "Name", "Price", "Quantity", "Subtotal");
    for (int i = 0; i < count; i++)
    {
        float subtotal = cart.items[i].price * cart.items[i].quantity;
        total += subtotal;
        printf("%-10s%-10.2f%-10d%-10.2f\n", cart.items[i].name, cart.items[i].price, cart.items[i].quantity, subtotal);
    }
    printf("----------------------------------------\n");
    printf("Total cart value: %.2f\n", total);
}