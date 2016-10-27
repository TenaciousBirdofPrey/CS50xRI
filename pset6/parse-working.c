#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdbool.h>

#include <stdlib.h>



bool parse(const char* line, char* abs_path, char* query);

int main (void)
{
   //const char* line = "GET /index.HTML?=queryisthisline HTTP/1.1";
     const char* line = "GET / HTTP/1.1";
     char abs_path[120];
     char query[100];
    parse(line,abs_path,query);
    printf("from function abs_path:%s\n and query: %s\n",abs_path,query);
}
/**
 * Parses a request-line, storing its absolute-path at abs_path 
 * and its query string at query, both of which are assumed
 * to be at least of length LimitRequestLine + 1.
 */

bool parse(const char* line, char* abs_path, char* query)
{
//copy line
int len = strlen(line);
char copy[len];
for (int i =0;i<len;i++)
{
    copy[i]=line[i];
}

//run checks-if method is not GET, respond to the browser with 405
//Method Not Allowed and return false;
char *get ="GET";
if(strstr(copy, get) == NULL)
{
    //error(405);
    return false;
}
//if request-target does not begin with /, 
//respond to the browser with 501 Not Implemented and return false;
char *slashcheck = strchr(line,' ')+1;
if (*slashcheck != '/')
{
    //error(501);
    return false;
}
//if HTTP-version is not HTTP/1.1,
//respond to the browser with 505 HTTP Version Not Supported and return false; or
char *ver_1 ="HTTP/1.1";
if(strstr(line, ver_1) == NULL)
{
    //error(505);
    return false;
}



//get path
char *path= strchr(line,' ')+1;//create pointer to just after first space
char *endpath = strchr(path,' ');// creat pointer to second space
int path_len = endpath - path +1;// determine path length with pointer math
char pathQuery[path_len+1 ];//create array to put it
strncpy(pathQuery,path,path_len);//put it in nice and slow
pathQuery[path_len]= '\0';//terminate the muthafuckin' null!

printf("request is:%s\n",pathQuery);


//get query out of pathQuery
char *start_query = strchr(pathQuery,'?')+1;
printf("start query: %s\n",start_query);
  
//isolate path
char* end_path = strchr(pathQuery,'?');//make pointer to qustion mark
int pathlen = end_path-pathQuery;//use pointer math to determin len
char finalpath[pathlen];
strncpy(finalpath,pathQuery,pathlen);
finalpath[pathlen]='\0';

printf("final path: %s\n",finalpath);
//if request-target contains a ",
//respond to the browser with 400 Bad Request and return false;
//char *apos=""";
if(strchr(finalpath,'"' ) != NULL) {
    //error(400)
    return false;
}



//assign to abs_path
int fp_len =strlen(finalpath);
int q_len = strlen(start_query);
printf("finalpath is %i\n",fp_len);
printf("start query is: %i\n",q_len);

//equate to passed variables

for (int i=0;i<q_len;i++)
{
    query[i]=start_query[i];
}

for (int i = 0; i<fp_len;i++)
{
    abs_path[i]=finalpath[i];
}


//abs_path = &(*finalpath);
//start_query = &(*query);
//printf("address fp=%p and abs= %p\n",finalpath,abs_path );

  
  return true;

/*
char words[] = "Hello Dr. Chandra";
char *secondWord = strchr(words, ' ') + 1; // get a pointer to just after the space
char *endTitle = strchr(secondWord, '.'); // get a pointer to the period
int titleLength = endTitle - secondWord  + 1; // pointer arithmetic FTW!
char title[titleLength  + 1]; // alloc space to hold the title
strncpy(title, secondWord, titleLength);
title[titleLength] = '\0';
*/
}