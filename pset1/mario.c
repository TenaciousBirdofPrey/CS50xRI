# include <stdio.h>
# include <cs50.h>

int main (void)
{
 // Retrieve the needed height for pyramid.
 
 int height;
 printf(" how tall do you want this pyramid?\n");
     // loops until conditions met
     do
     {
      printf("Enter a height between 1 and 23 blocks"); 
      height = GetInt();
     }
     while(height < 0 || height > 23);
 // confirms condition is met    
 //printf("ok the height is %d blocks\n", height);
 




// build the pyramid x lines high.


// line variable used to control while loop. It increments up 1 per iteration until it equals height
int line = 0;
// since first line depends on height, this w_space is used in for loop to control how many spaces to print
int w_spaces = height -1;
//this determines how many hashes to print initialy
int hashes = 2;




while (line < height)
{
 for(int i = w_spaces; i > 0; i--)
  {
  printf(" ");
  } 
 for (int z = 0; z < hashes; z++ )
  {
   printf("#");
  }
  
  
  
 
printf("\n"); 
line++; 
w_spaces = w_spaces -1;
hashes = hashes + 1;
}
    
    
}