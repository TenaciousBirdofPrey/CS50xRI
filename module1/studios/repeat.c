# include <stdio.h>
# include <cs50.h>

int main (void)
{
 

  printf("what do you want me to say?");
  string say = GetString();
  printf("how many times should I say it");
  int count = GetInt();
  int i;
  for(i=count;i>0;i--)
  {
  printf("%s\n",say);  
  }
    
}


