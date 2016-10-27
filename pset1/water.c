# include <stdio.h>
# include <cs50.h>
# include <math.h>

// 192 oz per minute


int main (void)
{
 int shower_minutes;
 int bottle = 16;
 int flow = 192;
 
 printf("how long of a shower are you going to take?");
 

 do 
 {

 shower_minutes = GetInt();
 printf("needs to be a number above 0");
 
 }
 while (shower_minutes < 0);
 
 printf("That's the equivelant of %d bottles of water\n",(flow*shower_minutes)/bottle);
    
    
    
}


