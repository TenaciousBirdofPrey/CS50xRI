# include <stdio.h>
# include <cs50.h>

int main (void)
{
    int n;
    printf("let's get the rockets running.\n count down begins at?\n");
    n = GetInt();
    while (n<0)
    {
        printf("yo dawg...I'm gonna need a postivt number\n");
        n = GetInt();
    }
    printf("countdown begins at %i\n", n);
    while (n>0)
    {
        printf("%i...\n", n);
        n --;
    }
    printf("blast off\n");
    
    
    
}