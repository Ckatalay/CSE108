#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float hw_avg(int gra[10][5], int n);
float calculateWeightedAverage(int gra[10][5], int i);
int isPass(float avg);
char grade_name(int n);

int main(void)
{
    int grades[10][5];

    srand(time(NULL));

    printf("=== Raw Grades [grades[10][5]] ===\nStudent |"
           "%7s %7s %5s %7s %6s\n", "Midterm", "Final", "HW1", "HW2", "HW3");

    for (int i = 0; i < 10; i++)
    {
        printf("%5d   |", i + 1);
        for (int j = 0; j < 5; j++)
        {
            grades[i][j] = rand() % 101;
            printf("%7d", grades[i][j]);
        }
        printf("\n");
    }

    float analysis[10][3];
    float sum = 0;
    int passing = 0;
    int letter_code[5] = { 0 };

    for (int i = 0; i < 10; i++)
    {  
        float avg = calculateWeightedAverage(grades, i);
        analysis[i][0] = avg;
        sum += avg;

        if (isPass(avg))
        {
            analysis[i][1] = 1.0;
            passing++;
        }
        else
        {
            analysis[i][1] = 0.0;
        }

        if (avg >= 90)
        {
            analysis[i][2] = 5.0;
            letter_code[4]++;
        }
        else if (avg >= 75)
        {
            analysis[i][2] = 4.0;
            letter_code[3]++;
        }
        else if (avg >= 65)
        {
            analysis[i][2] = 3.0;
            letter_code[2]++;
        }
        else if (avg >= 50)
        {
            analysis[i][2] = 2.0;
            letter_code[1]++;
        }
        else
        {
            analysis[i][2] = 1.0;
            letter_code[0]++;
        }
    }

    printf("%6s|%11s|%6s|%6s\n", "Student ", " Final Grade ", "Pass ", " Letter Code ");
    for (int i = 0; i < 10; i++)
    {
        printf("%5d   |", i + 1);
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
            printf("%10.2f   |", analysis[i][j]);
            }
            else if (j == 2)
            {
            printf("%5.0f", analysis[i][j]);
            }
            else
            {
            printf("%5.0f |", analysis[i][j]);
            }
        }
        printf("\n");
    }
    printf("Legend: 5 = A, 4 = B, 3 = C, 2 = D, 1 = F\n");

    FILE *class = fopen("class_report.txt", "w");

    if (class == NULL)
    {
        printf("Cannot open file.\n");
    }

    float class_avg = sum / 10.0;

    printf("=== Class Report ===\n"
           "- Average Final Grade: %2.f\n"
           "- Passing Students   : %d / 10\n"
           "- Letter Grade Distribution:\n"
           , class_avg, passing);
    fprintf(class, "=== Class Report ===\n"
           "- Average Final Grade: %2.f\n"
           "- Passing Students   : %d / 10\n"
           "- Letter Grade Distribution:\n"
           , class_avg, passing);
    for (int i = 4; i > -1; i--)
    {
        printf("%c (%d): %d\n", grade_name(i + 1), i + 1, letter_code[i]);
        fprintf(class, "%c (%d): %d\n", grade_name(i + 1), i + 1, letter_code[i]);
    }
    printf("- Class Performance: ");
    fprintf(class, "- Class Performance: ");

    if (class_avg >= 85)
    {
        printf("Excellent\n");
        fprintf(class, "Excellent\n");
    }
    else if (class_avg >= 70)
    {
        printf("Satisfactory\n");
        fprintf(class, "Satisfactory\n");
    }
    else
    {
        printf("Needs Improvement\n");
        fprintf(class, "Needs Improvement\n");
    }

    fclose(class);
}

float hw_avg(int gra[10][5], int n)
{
    float sum = 0;

    for (int i = 2; i < 5; i++)
    {  
        sum += (float)gra[n][i];
    }

    return sum / 3;
}

float calculateWeightedAverage(int gra[10][5], int i)
{
    return 0.3 * (float)gra[i][0] + 0.4 * (float)gra[i][1] + 0.3 * hw_avg(gra, i);
}

int isPass(float avg)
{
    if (avg >= 50)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char grade_name(int n)
{
    if (n == 5) return 'A';
    if (n == 4) return 'B';
    if (n == 3) return 'C';
    if (n == 2) return 'D';
    if (n == 1) return 'F';
    return 'e';
}