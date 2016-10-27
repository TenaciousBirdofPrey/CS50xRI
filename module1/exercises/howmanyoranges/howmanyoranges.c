# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main (void)
{
    float oranges;
    double amount;
    printf("how many orange slices do you want?");
    oranges = GetInt();
    amount = ceil(oranges/8);
    printf("then go buy %.2f oranges \n",amount);
    
    
    
    
}


