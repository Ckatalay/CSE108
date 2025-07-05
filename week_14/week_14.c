#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CIRCLE -1
#define RECTANGLE -2
#define TRIANGLE -3

typedef struct node_t
{
    int val;
    struct node_t *next;
} node_t;

node_t *generate(int n);
void process_circle(node_t **head);
void process_rectangle(node_t **head);
void process_triangle(node_t **head);

int main(void)
{
    srand(time(NULL));

    int n;
    printf("generate ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid number of entities.\n");
        return 1;
    }
    node_t *head = generate(n);

    while(head != NULL)
    {
        printf("process ");
        char shape[20];
        scanf("%s", shape);

        switch (shape[0])
        {
        case 'c':
            process_circle(&head);
            break;

        case 't':
            process_triangle(&head);
            break;

        case 'r':
            process_rectangle(&head);
            break;
        
        default:
            printf("Invalid shape type.\n");
            break;
        }
    }
    printf("All the entities are processed.\n");
}

node_t *generate(int n)
{
    node_t *head = malloc(sizeof(node_t));
    node_t *current = head;
    for (int i = 0; i < n; i++)
    {
        int type = (rand() % 3) - 3;

        switch (type)
        {
        case CIRCLE:
            if (current->next == NULL && i != 0)
            {
                current->next = malloc(sizeof(node_t));
                current = current->next;
            }
            current->val = CIRCLE;
            current->next = malloc(sizeof(node_t));
            current = current->next;
            current->val = rand() % 100;
            current->next = NULL;
            break;

        case RECTANGLE:
            if (current->next == NULL && i != 0)
            {
                current->next = malloc(sizeof(node_t));
                current = current->next;
            }
            current->val = RECTANGLE;
            current->next = malloc(sizeof(node_t));
            current = current->next;
            current->val = rand() % 100;
            current->next = malloc(sizeof(node_t));
            current = current->next;
            current->val = rand() % 100;
            current->next = NULL;
            break;

        case TRIANGLE:
            if (current->next == NULL && i != 0)
            {
                current->next = malloc(sizeof(node_t));
                current = current->next;
            }
            current->val = TRIANGLE;
            current->next = malloc(sizeof(node_t));
            current = current->next;
            current->val = rand() % 100;
            current->next = malloc(sizeof(node_t));
            current = current->next;
            current->val = rand() % 100;
            current->next = NULL;
            break;
        
        default:
            break;
        }
    }
    return head;
}

void process_circle(node_t **head)
{
    node_t *current = *head;
    node_t *tri_prev = NULL;
    node_t *tri = NULL;

    while (current != NULL)
    {
        if (current->val == CIRCLE)
        {
            tri = current;
            break;
        }
        tri_prev = current;
        current = current->next;
    }

    if (tri == NULL)
    {
        printf("No circle found!\n");
        return;
    }

    node_t *side1 = tri->next;

    printf("Circle: circle %.2f\n", (float)side1->val / 10);


    if (tri_prev == NULL)
    {
        *head = side1->next;
    }
    else
    {
        tri_prev->next = side1->next;
    }

    free(tri);
    free(side1);
}

void process_rectangle(node_t **head)
{
    node_t *current = *head;
    node_t *tri_prev = NULL;
    node_t *tri = NULL;

    while (current != NULL)
    {
        if (current->val == RECTANGLE)
        {
            tri = current;
            break;
        }
        tri_prev = current;
        current = current->next;
    }

    if (tri == NULL)
    {
        printf("No rectangle found!\n");
        return;
    }

    node_t *side1 = tri->next;
    node_t *side2 = side1->next;

    printf("Rectangle: rectangle %.2f %.2f\n", (float)side1->val / 10, (float)side2->val / 10);

    if (tri_prev == NULL)
    {
        *head = side2->next;
    }
    else
    {
        tri_prev->next = side2->next;
    }

    free(tri);
    free(side1);
    free(side2);
}

void process_triangle(node_t **head)
{
    node_t *current = *head;
    node_t *tri_prev = NULL;
    node_t *tri = NULL;

    while (current != NULL)
    {
        if (current->val == TRIANGLE)
        {
            tri = current;
            break;
        }
        tri_prev = current;
        current = current->next;
    }

    if (tri == NULL)
    {
        printf("No triangle found!\n");
        return;
    }

    node_t *side1 = tri->next;
    node_t *side2 = side1->next;

    printf("Triangle: triangle %.2f %.2f\n", (float)side1->val / 10, (float)side2->val / 10);

    if (tri_prev == NULL)
    {
        *head = side2->next;
    }
    else
    {
        tri_prev->next = side2->next;
    }

    free(tri);
    free(side1);
    free(side2);
}