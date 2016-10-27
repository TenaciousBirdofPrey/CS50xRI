/**
 * leaky.c
 *
 */

#include <stdio.h>
#include <cs50.h>

typedef struct
{
    char* firstName;
    char* lastName;
} person;

int main(void)
{
    person* peep = malloc(sizeof(person));

    printf("first name please:\n");
    peep->firstName = GetString();

    printf("last name please:\n");
    peep->lastName = GetString();

    printf("Nice to meet you, %s %s!\n", peep->firstName, peep->lastName);
    free(peep->firstName);
    free(peep->lastName);
    free(peep);
}

//http://stackoverflow.com/questions/8634293/what-is-a-memory-leak-in-structures-how-can-we-rectify-that