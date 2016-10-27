# include <stdio.h>
# include <cs50.h>

int main (void)
{
    printf(" Today's special is artisinal flax dusted whole wheat, biscuit induced munchkins\n");
    printf(" How many donuts do you want?\n");
    float amount = GetFloat();
    printf(" What do you want to pay\n");
    float price = GetFloat();
    printf("ok...thatwill be %.2f\n", (amount*price)*1.05 );
    
    
}