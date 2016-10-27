# include <cs50.h>
# include <stdio.h>

int main (void)
{
    printf (" give me a number");
    float x = GetFloat();
    printf ("give me another number");
    float y = GetFloat();
    printf ("the ration bewteen %f and %f is %f\n",x,y,x*100/y);
    
}