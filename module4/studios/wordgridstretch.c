# include <stdio.h>
# include <cs50.h>
# include <string.h>



int main(int argc, char* argv[])
{
// test for 4 arguments
if (argc > 4)
return 1;
// test all same lengths and print current word grid status
int length_1 = strlen(argv[1]);
int length_2 = strlen(argv[2]);
int length_3 = strlen(argv[3]);



if (length_1 == length_2 && length_2==length_3)
    {//start if
    printf("Your word grid currently looks like this:\n\n");
    for (int i = 1; i<argc; i++)
    {//start for
    printf("%s\n\n",argv[i]);
    }//end for    
    }// end if
else
return 1;

//stretch that muscle
int stretch;
printf("Now I will stretch it out vertically. How much should I stretch by?");
stretch = GetInt();
printf("After stretching by %i, you now have this!\n",stretch);



//vetical loops
for (int i = 1; i<4;i++)//grab argv then next argv then next arg v
{   
    for (int line = 0; line<stretch;line++)// prints line stretch times
    {
        for(int j=0;j<strlen(argv[i]); j++)//grabs jth element of argvi
        {
            for (int spin = 0; spin<stretch;spin++)
            {
                printf("%c",argv[i][j]);//prints Jth element stretch times
            } 
      
        }
    printf("\n");
    }
}

}

