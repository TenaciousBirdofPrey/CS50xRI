# include <stdio.h>
# include <cs50.h>
# include <string.h>

int main ()
{
    printf("what d'ya say mate?\n");
    char* say = GetString();
    
    
    char* copy = malloc( (strlen(say)+1)*sizeof(char));
    if (copy == NULL)
    {
        free(say);
        return 1;
    }
    
    for (int i =0;i<strlen(say);i++)
    {
        copy[i]=say[i];
    }
 printf("%s%s\n",say,copy);   
    
}