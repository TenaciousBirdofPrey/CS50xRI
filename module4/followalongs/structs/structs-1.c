# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include "structs.h"

# define STUDENTS 3

int main (void)
{
    student students[STUDENTS];
    for (int i = 0; i<3; i++)
    {
        printf("Students name:\n");
        students[i].name= GetString();
        printf("Students house: \n");
        students[i].house = GetString();
    }
    
    FILE* file = fopen("students.csv", "w");
    if (file != NULL)
    {
        for (int i = 0; i<3; i ++)
        {
            fprintf(file, "%s,%s\n",students[i].name, students[i].house);
        }
    }
    
    
    
    
    for (int i=0; i<3; i++)
    {

        free (students[i].name);
        free (students[i].house);
    }
}