# include <cs50.h>
# include <stdio.h>
# include <string.h>

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
    
    for (int i=0; i<3; i++)
    {
        printf("%s is in %s\n",students[i].name,students[i].house);
        free (students[i].name);
        free (students[i].house);
    }
}