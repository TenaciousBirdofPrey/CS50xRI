# include <cs50.h>
# include <stdio.h>
# include <stdlib.h>

int* getAge(int arr[]);

int main(int argc,char* argv[])
{
    if (argc > 1)
    {
        return 1;
    }
    int num_dol = atoi(argv[1]);
    if (num_dol <0)
    {
        return 2;
    }
    int train[num_dol];

    for (int i = 0;i<num_dol;i++)
    {  
        getAge(train);
    }

    for (int i = 0; i<num_dol; i++)
    {
        printf("%i\n",train[i]);
    }
}

    
    int  getAge(int arr[])
    {
        printf("What is the age of dolphin number %i?:",i+1);
        int age = GetInt();
        train[i]= age;
        
    }