# include <stdio.h>
# include <cs50.h>
# include <string.h>

int main (int argc, string argv[])
{

if (argc!= 4)
   {
   printf("must be 3 words\n");
   return 1;
   }
   
for (int i = 1; i < 4; i++)
{
   if (  strlen(argv[i])>3  )
   {
      printf("%s is more then three letters.\n",argv[i]);
      return 1;  
   }   
}



for (int i = 0; i < 4; i++)
{
  for (int j = 1 ;j<4 ; j++)
  {
  printf("%c  ",argv[j][i]);
  }
printf("\n\n");
}    
printf("\n");    
}









//for( a = 10; a < 20; a++ )
//   {
//      printf("value of a: %d\n", a);
//   }
// 
//   return 0;
//   }

   /* local variable definition */
//   int a = 10;



   /* do loop execution */
//   do {
//      printf("value of a: %d\n", a);
//      a = a + 1;
//      }
//   while( a < 20 );
// 
//   return 0;
//   }

// ITERATE OVER A STRING
// }int n = strlen(my_string);
// for (int i = 0; i < n; i++) 
// {
//     char c = my_string[i];
// }
