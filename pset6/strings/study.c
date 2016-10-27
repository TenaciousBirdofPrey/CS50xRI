#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* copy_ptr(char* orig);
char* concat(char* first,char* second);




int main(void)
{
 char *ptr_abc = "/directory/to/folder";
 char *ptr_misc = "/index.php";
 char  abc[] = "uvwxyz 123 456=";
 char  misc[]= "this is just misc=";
 
 printf("ptr_abc is: %s\nptr_misc: %s\n",ptr_abc,ptr_misc);
 printf("abc: %s \nthis is misc: %s\n",abc,misc);
 
 // copy *char also supports char
 printf("-------------------------- \n");
 printf("copy of ptr_abc: %s\n\n",copy_ptr(ptr_abc));
 
 //concat
 printf("-------------------------- \n");
 printf("concat is: %s\n\n", concat(ptr_abc,ptr_misc));
 
 
 printf("------------reddit-------------- \n");
char words[] = "Hello Dr. Chandra";
char *secondWord = strchr(words, ' ') + 1; // get a pointer to just after the space
char *endTitle = strchr(secondWord, '.'); // get a pointer to the period
int titleLength = endTitle - secondWord  + 1; // pointer arithmetic FTW!
printf("tittLength: %i\n",titleLength);
char title[titleLength  + 1]; // alloc space to hold the title
strncpy(title, secondWord, titleLength);
title[titleLength] = '\0';
printf("title: %s\n",title);



}

char* copy_ptr(char* orig)
{
    char *copy = malloc(sizeof(orig));
    strcpy(copy,orig);
    
    return copy;
    free(copy);
}

char* concat(char* first, char* second)
{
    //char *strcat(char *dest, const char *src);
    
    char* space=malloc(sizeof(first)+sizeof(second));
    strcat(space,first);
    strcat(space,second);
    
    return space; 
}