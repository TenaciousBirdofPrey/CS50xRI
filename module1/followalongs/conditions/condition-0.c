#include <stdio.h>
# include <cs50.h>

int main(void)
{
    printf("please give me a number.\n");
    int n = GetInt();
    
    if (n>0)
    {
        printf("you picked a positive number!\n");
        
    }
    else
    {
        printf("you picked a negative number!\n");
    }
    
}