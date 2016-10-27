# include <stdio.h>
# include <cs50.h>

int main (void)
{
 int h;
 int w;
 printf("input height\n");
 h = GetInt();
 printf("input width\n");
 w = GetInt();
 
 int line = 0;
 
 while (line < h)
 {
     for (int heart = 0; heart < w; heart++)
     {
     printf("<3");
     }
     line++;
     printf("\n");
 }
    
    
}


