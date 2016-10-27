# include <stdio.h>
# include <cs50.h>

int main (void)
{
    printf("how old are you?");
    int x = GetInt();
    if (x<16)
    {
        printf("you can't do much!\n");      
    }
    if (x> 15 && x< 18)
    {
        printf("you can drive\n");
    }
        if (x> 17 && x< 21)
    {
        printf("you can drive\n you can vote\n");
    }
        if (x> 20 )
    {
        printf("you can drive\n you can vote\n you can drink\n");
    }

    
    
    
    
}

