# include <string.h>
# include <stdio.h>
# include <cs50.h>

int main (void)
{
printf("first word?");
char*  s = GetString();
int len = strlen(s);
printf("second word?");
char*  t = GetString();
int len2 = strlen(t);

if(len != len2)
{
return 1;
}
 int check = 0;
 for (int i =0; i<len; i++)
 {
         if ( *(s+i)== *(t+i))
         printf("%c  =  %c\n",*(s+i), *(t+i) );
         else
         {
         printf("%c !=  %c\n", *(s+i),*(t+i) );
         check++;
         }
}
    if (check > 0)
    printf("These words are DIFFERENT!!!!!!!\n");
    else
    printf("These words are the same!\n");
}