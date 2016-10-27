#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>


#include <stdbool.h>

#include <stdlib.h>



bool parse(const char* line, char* abs_path, char* query);

int main (void)
{
    const char* line = "GET /cat.JPG HTTP/1.1";
     char abs_path[8191];
     char query[50];
    parse(line,abs_path,query);
}


/**
 * Parses a request-line, storing its absolute-path at abs_path 
 * and its query string at query, both of which are assumed
 * to be at least of length LimitRequestLine + 1.
 */
 
 
 

bool parse(const char* line, char* abs_path, char* query)
{
 //copy line-because strange thing happen if I don't
 int len = strlen(line);
 char copy_line[len];
 for (int i=0;i<len;i++)
 {
     copy_line[i]=line[i];
 }
 printf("copy of line is %s\n",copy_line);
 
 
 
 
 
 //variables to help find spaces

int space1 = 0;
int space2 = 0;

//finds first space
for (int i = 0; space1==0;i++)
{
    if (copy_line[i]==' ')
    {
        space1=i;
    }
}
//finds second space
for (int i = 0;i<len;i++)
{
    if (copy_line[i]==' ')
    {
        space2=i;
    }
}


// arrays to put strings in
char method[space1];
char path[space2-space1];
char http_v[len - space2];

//put method in method array insert null term
for (int i = 0;i<space1;i++)
{
    method[i]=copy_line[i];
}
   
   method[space1]='\0';
   printf("method on line 83 is %s\n",method);
    
   

   
 //put path in  array insert null term
for (int i = space1+1; i<space2; i++)
{
    path[i]=copy_line[i];
    
}
   printf("path on line 94 is %s\n",path);    
    path[space2]='\0';
 
    
  


for (int i = space2+1; i<len; i++)
{
    http_v[i]=copy_line[i];
    
}
   
    http_v[len]='\0';
    printf("http_v on line 108 is %s\n",http_v);



// arrays suddenly change values?

printf("method on line 114 is :%s\n",method);
printf("path on line 115:%s\n",path);
printf("http_v on line 116 is %s\n",http_v);

  
  
  return true;
}

