# include <stdio.h>
# include <cs50.h>
#include <math.h>

int main (void)
{
    
//prompt user for amount of change owed.
float cash;
   do
   {
    printf("Please enter the amount of change owed \n It must be great then 0 \n"); 
    cash = GetFloat();
   }    
   while (cash<0); 
   
// round up and convert to float

float coin_cash;
coin_cash = cash*100;
int rounded_cash;
rounded_cash = round(coin_cash);


//printf("that is %d in coins\n", rounded_cash);
int coins;
do
{
    if (rounded_cash == 1)
        {
        rounded_cash = rounded_cash - 1;
        coins = coins+1;
        }
    if (rounded_cash >= 5 && rounded_cash < 10)
        {
        rounded_cash = rounded_cash - 5;
        coins = coins+1;
        }
    if (rounded_cash >= 10 && rounded_cash < 25)
        {
        rounded_cash = rounded_cash - 10;
        coins = coins+1;
        }
    if (rounded_cash >= 25 )
        {
        rounded_cash = rounded_cash - 25;
        coins = coins+1;
    }





    
}
while(rounded_cash > 0);

printf("%d\n",coins);
}


