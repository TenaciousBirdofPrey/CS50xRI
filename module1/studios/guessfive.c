# include <stdio.h>
# include <cs50.h>

int main (void)
{
  int answer = 2;
  int guess;
  int limit = 5;
  int count = 1;
  
  
  printf("I'm thinking of a number between 0 and 10...can you guess?\n");
  guess = GetInt();
  

  
    for ( limit = 5; count < limit; count++ )
        {
            
            printf("Wrong..guess again.\n");
            guess = GetInt();
 //           count ++;
        }
    if (guess == answer)
    {
      printf("you must be psychic\n" );
    }
    else
    {
       printf("sorr you are out of guesses\n");
    }



}


