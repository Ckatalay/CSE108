#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    char surname[100];
    char dep[100];
    char class_1[100];
    char class_2[100];
    double salary;
} type_I;

typedef struct
{
    char name[100];
    char surname[100];
    double salary;
    char degree;
} type_E;

typedef union
{
    type_E employee;
    type_I instructor;
} person_t;

typedef struct
{
    char p;
    person_t person;
} combine_type;

combine_type combine_type_salary_rise(combine_type person_info);
void print_person(char *input, char *output);

int main(void)
{
    print_person("input.txt", "output.txt");
    return 0;
}

combine_type combine_type_salary_rise(combine_type person_info)
{
    switch (person_info.p)
    {
    case 'I':
        person_info.person.instructor.salary *= 1.053;
        break;

    case 'E':
        switch (person_info.person.employee.degree)
        {
            case 'a':
                person_info.person.employee.salary *= 1.175;
                break;

            case 'b':
                person_info.person.employee.salary *= 1.12;
                break;

            case 'c':
                person_info.person.employee.salary *= 1.09;
                break;
            
            default:
                break;
        }
        break;
    default:
        break;
    } 

    return person_info;
}

void print_person(char *input, char *output)
{
    FILE *in = fopen(input, "r");

    if (in == NULL)
    {
        printf("Error opening input file\n");
        return;
    }

    combine_type person_info[100];
    int i = 0;
    char line[4096];
    
    while (fgets(line, sizeof(line), in))
    {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        
        char *token = strtok(line, ",");
        
        if (token != NULL && strcmp(token, "Instructor") == 0)
        {
            person_info[i].p = 'I';
            
            // Parse name and surname
            token = strtok(NULL, ",");
            if (token != NULL) {
                // Skip leading space if any
                if (token[0] == ' ') token++;
                
                char *space = strchr(token, ' ');
                if (space) {
                    *space = '\0';
                    strcpy(person_info[i].person.instructor.name, token);
                    strcpy(person_info[i].person.instructor.surname, space + 1);
                }
            }
            
            // Department
            token = strtok(NULL, ",");
            if (token != NULL) {
                if (token[0] == ' ') token++;
                strcpy(person_info[i].person.instructor.dep, token);
            }
            
            // Class 1
            token = strtok(NULL, ",");
            if (token != NULL) {
                if (token[0] == ' ') token++;
                strcpy(person_info[i].person.instructor.class_1, token);
            }
            
            // Class 2
            token = strtok(NULL, ",");
            if (token != NULL) {
                if (token[0] == ' ') token++;
                strcpy(person_info[i].person.instructor.class_2, token);
            }
            
            // Salary
            token = strtok(NULL, ",");
            if (token != NULL) {
                sscanf(token, "%lf", &person_info[i].person.instructor.salary);
            }
            
            person_info[i] = combine_type_salary_rise(person_info[i]);
        }
        else if (token != NULL && strcmp(token, "Employee") == 0)
        {
            person_info[i].p = 'E';
            
            // Parse name and surname
            token = strtok(NULL, ",");
            if (token != NULL) {
                if (token[0] == ' ') token++;
                
                char *space = strchr(token, ' ');
                if (space) {
                    *space = '\0';
                    strcpy(person_info[i].person.employee.name, token);
                    strcpy(person_info[i].person.employee.surname, space + 1);
                }
            }
            
            // Salary
            token = strtok(NULL, ",");
            if (token != NULL) {
                sscanf(token, "%lf", &person_info[i].person.employee.salary);
            }
            
            // Degree
            token = strtok(NULL, ",");
            if (token != NULL) {
                if (token[0] == ' ') token++;
                person_info[i].person.employee.degree = token[0];
            }
            
            person_info[i] = combine_type_salary_rise(person_info[i]);
        }
        i++;
    }
    
    fclose(in);

    FILE *out = fopen(output, "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        return;
    }

    for (int j = 0; j < i; j++)
    {
        if (person_info[j].p == 'I')
        {
            fprintf(out, "Instructor, %s %s, %s, %s, %s, %.2f\n", 
                    person_info[j].person.instructor.name, 
                    person_info[j].person.instructor.surname,
                    person_info[j].person.instructor.dep, 
                    person_info[j].person.instructor.class_1, 
                    person_info[j].person.instructor.class_2,
                    person_info[j].person.instructor.salary);
        }
        else if (person_info[j].p == 'E')
        {
            fprintf(out, "Employee, %s %s, %.2f, %c\n", 
                    person_info[j].person.employee.name, 
                    person_info[j].person.employee.surname,
                    person_info[j].person.employee.salary, 
                    person_info[j].person.employee.degree);
        }
    }
    
    fclose(out);
}