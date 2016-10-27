# include <stdio.h>
# include <cs50.h>

int main (void)
{
    printf("Yo Dawg I heard you like books\n What's your favorite one?\n");
    string book = GetString();
    printf("No way! I love %s \n", book);
    printf("oops...NVMD %s is just meh \n", book);
    
}