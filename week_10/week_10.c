#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char surname[20];
    int id;
    int midterm;
    int final;
    double average;
    char letter;
} student_t;

typedef struct
{
    student_t students[100];
    int count;
    double threshold;
} class_t;

student_t get_student(void);
void is_passing(int threshold, student_t *student);
void sort(class_t *class);
void update_final(int final, int id, class_t *class);
void print_students(class_t class);

int main(void)
{
    class_t class;
    char name[20];
    int c;

    while (1)
    {
        printf("Passing threshold: ");
        if (scanf("%lf", &class.threshold) != 1)
        {
            printf("Invalid grade.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    class.count = 0;
    while (strcmp(name, "Stop") != 0)
    {
        printf("Student %d\n", class.count + 1);
        class.students[class.count] = get_student();
        strcpy(name, class.students[class.count].name);
        is_passing(class.threshold, &class.students[class.count]);
        class.count++;
    }

    print_students(class);
    printf("#call sorting function\n");
    sort(&class);
    print_students(class);

    printf("Update Final Grade:\n");

    int id;
    while (1)
    {
            printf("Enter ID: ");
        if (scanf("%d", &id) != 1)
        {
            printf("Invalid ID.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    int final;
    while (1)
    {
        printf("Enter new final grade: ");
        if (scanf("%d", &final) != 1)
        {
            printf("Invalid final.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    update_final(final, id, &class);
    print_students(class);
}

student_t get_student(void)
{
    char name[20];
    char surname[20];
    student_t student;
    char c;

    while (1)
    {
        printf("Enter name: ");
        if (scanf("%s", name) != 1)
        {
            printf("Invalid name.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    strcpy(student.name, name);

    while (1)
    {
        printf("Enter surname: ");
        if (scanf("%s", surname) != 1)
        {
            printf("Invalid surname.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    strcpy(student.surname, surname);

    while (1)
    {
        printf("Enter ID: ");
        if (scanf("%d", &student.id) != 1)
        {
            printf("Invalid ID.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Enter midterm grade: ");
        if (scanf("%d", &student.midterm) != 1 || student.midterm < 0 || student.midterm > 100)
        {
            printf("Invalid midterm.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Enter final grade: ");
        if (scanf("%d", &student.final) != 1 || student.final < 0 || student.final > 100)
        {
            printf("Invalid final.\n");
            while ((c = getchar()) != '\n');
            continue;
        }
        break;
    }

    return student;
}

void is_passing(int threshold, student_t *student)
{
    student->average = (student->midterm * 0.4) + (student->final * 0.6);

    if (student->average >= threshold)
    {
        student->letter = 'P';
    }
    else
    {
        student->letter = 'F';
    }
}

void sort(class_t *class)
{
    int count = class->count - 1;
    for (int i = 0; i < count; i++)
    {
        for (int j = i; j < count - i - 1; j++)
        {
            if (class->students[j].average < class->students[j + 1].average)
            {
                if (strcmp(class->students[j].name, "Stop") == 0 || strcmp(class->students[j + 1].name, "Stop") == 0)
                {
                    continue;
                }
                student_t temp = class->students[j];
                class->students[j] = class->students[j + 1];
                class->students[j + 1] = temp;
            }
        }
    }
}

void update_final(int final, int id, class_t *class)
{
    for (int i = 0; i < class->count; i++)
    {
        if (class->students[i].id == id)
        {
            class->students[i].final = final;
            is_passing(class->threshold, &class->students[i]);
            break;
        }
    }
}

void print_students(class_t class)
{
    printf("Class Information:\n------------------------\n");
    printf("%7s %7s %7s %7s %7s %7s %7s\n",
           "Name", "Surname", "ID", "Midterm", "Final", "Average", "Grade");
    printf("------------------------\n");

    int passing = 0;
    double average = 0;
    for (int i = 0; i < class.count; i++)
    {
        if (strcmp(class.students[i].name, "Stop") == 0)
        {
            continue;
        }
        printf("%7s %7s %7d %7d %7d %7.2f %7c\n",
               class.students[i].name, class.students[i].surname, class.students[i].id,
               class.students[i].midterm, class.students[i].final, class.students[i].average, class.students[i].letter);

        if (class.students[i].letter == 'P')
        {
            passing++;
        }
        average += class.students[i].average;
    }
    average /= (class.count - 1);
    printf("------------------------\n");
    printf("Passing students: %d\n", passing);
    printf("Class average: %.2f\n", average);
}