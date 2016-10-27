# include <stdio.h>
# include <cs50.h>

int main (void)
{
  int answer = 2;
  int guess;
  
  
  printf("I'm thinking of a number between 0 and 10...can you guess?\n");
  guess = GetInt();
  

  
    while ( guess != answer)
        {
            printf("Wrong..guess again.\n");
            guess = GetInt();
        }
    printf("You must be psychic\n"); 
  




}


