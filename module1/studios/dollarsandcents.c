# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main (void)
{
//prompt user for amount of change owed.
float cash;
printf("gimme a dollar amount: \n"); 
cash = GetFloat();
cash = roundf(cash*100)/100;

   

printf("Oh I think you mean %f \n", cash) ;   
    
    
}


