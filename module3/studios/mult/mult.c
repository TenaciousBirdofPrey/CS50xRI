/*
# include <stdio.h>
# include <cs50.h>
# include <string.h>

int main(void)
{
    int mult(int x, int y);
    printf("%i\n", mult(4,10));
}
*/
int mult(int x , int y)
{
   if ( y == 0)
   {
       return 0;
   }
   else
   return( x + mult(x, y-1));
 }