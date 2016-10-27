#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>



char* indexes(const char* path);


int main(void)
{
    const char *path = "/home/ubuntu/workspace/pset6/public/";
    printf("%s\n",indexes(path));
}


char* indexes(const char* path)
{

    //prepare php  char *strcat(char *dest, const char *src);
    
    // copy path
    char *Pcopy_path = malloc(sizeof(path));
    char *Hcopy_path = malloc(sizeof(path));
    int path_len = strlen(path);
    for (int i = 0; i < path_len;i++)
    {
        Pcopy_path[i]=path[i];
       
    }
      for (int i = 0; i < path_len;i++)
    {
        Hcopy_path[i]=path[i];
       
    }
    
    
    
    char *php = "index.php";
    char *path_php = malloc(sizeof(Pcopy_path)+sizeof(php)+1);
    strcat(path_php,Pcopy_path);
    strcat(path_php,php);
    

    printf("%s\n",path_php);
    //check if index.php in dir
    if (access(path_php,F_OK)==0)
    {
        printf("PHP it's here\n");
        return path_php;
    }
    
   //prepare html  char *strcat(char *dest, const char *src);
    char *html = "index.html";
    char *path_html = malloc(sizeof(Hcopy_path)+sizeof(html)+1);
    strcat(path_html,Hcopy_path);
    strcat(path_html,html);
    

    //printf("%s\n",path_html);
    //check if index.html in dir
    if (access(path_html,F_OK)==0)
    {
        printf("HTML it's here\n");
        return path_html;
    }
   
    
    //free(path_html);
    //free(path_php);
    return NULL;
    
}    
   

   

