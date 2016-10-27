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

    const char* line = "GET / HTTP/1.1";
    char abs_path[1200];
    char query[1000];
    parse(line,abs_path,query);
     printf("--------------------------------\n");
    printf("AT FUNCTION END:\nabs_path is:%s\nquery is:%s\n\n",abs_path,query);
}

bool parse(const char* line, char* abs_path, char* query)
{

//start of my code-------------------------------------------------------------    
    
    //copy line
    int len = strlen(line);
    char copy[len];
    for (int i =0;i<len;i++)
    {
    copy[i]=line[i];
    }

    //run checks-if method is not GET, 
    char *get ="GET";
    if(strstr(copy, get) == NULL)
    {
    //    error(405);
    return false;
    }
    
    //if request-target does not begin with /, 
    char *slashcheck = strchr(line,' ')+1;
    if (*slashcheck != '/')
    {
    //    error(501);
    return false;
    }
    
    //if HTTP-version is not HTTP/1.1,
    char *ver_1 ="HTTP/1.1";
    if(strstr(line, ver_1) == NULL)
    {
    //    error(505);
    return false;
    }



    //get path
    char *startpath= strchr(copy,' ')+1;//create pointer to just after first space
    //int len_startpath = strlen(startpath);
    //printf("startpath is: --%s--of length:%i\n\n",startpath,len_startpath);
    char *endpath = strchr(startpath,' ');// creat pointer to second space
    //int len_endpath = strlen(endpath);
    //printf("endpath is:--%s--of length:%i\n\n",endpath,len_endpath);
    int fullpath_len = endpath - startpath +1 ;// determine path length with pointer math
    //printf("fullpath_len is: %i\nendpath: %p\nminus startpath %p\n",fullpath_len,endpath,startpath);
    char fullpath[fullpath_len+1];//create array to put the path including query if it exists
    strncpy(fullpath,startpath,fullpath_len);//put it in nice and slow

    //holds full path
    fullpath[fullpath_len+1]= '\0';//terminate the muthafuckin' null!
    printf("fullpath is:%s\n\n",fullpath);
    printf("--------------------------------\n");


    //see if '?' exists--------------------------
         if (strchr(fullpath,'?') != NULL)
        {

        //get query out of pathQuery

        //isolate query
        char* question_mark = strchr(fullpath,'?')+1;//make pointer to just after qustion mark
        //printf("in ?!=NULL question_mark is:%s\n",question_mark);
        int querylen = strlen(question_mark);//determine len for array
        char finalquery[querylen];//creat array to hold final query
        strncpy(finalquery,question_mark,querylen);//slide that shit on in.
        //null already term

        int q_len = strlen(finalquery);
        for (int i=0;i<q_len;i++)
        {
        query[i]=finalquery[i];
        }
        
        //test
        printf("Inside ?!=null query is:%s\n",query);
    
       //adjust absolute path in consideration of ?
       //take out->char *startabs= strchr(copy,' ')+1;//create pointer to start of path
        char *endabs = strchr(fullpath,'?');// creat pointer to just before question mark
        
        int fullabs_len = endabs-fullpath;// determine absolute length with pointer math
        printf("--fullabs_len is:%i\n\n",fullabs_len);
        char absolutearray[fullabs_len];//create array to hold absolute 
        strncpy(absolutearray,fullpath,fullabs_len);//just the tip
        absolutearray[fullabs_len]='\0';//null gots to get terminated
        
        int abs_len =strlen(absolutearray);
        for (int i=0;i<abs_len;i++)
        {
        abs_path[i]=absolutearray[i];
        }
        
        //test
        printf("Inside ?!=null abs_path is:%s\n",abs_path);
    
    //done checkin for ?-------------------------------
    }



//if request-target contains a ",

if(strchr(fullpath,'"' ) != NULL)
{
    //error(400)
    return false;
}



    //assign to abs_path
    int fp_len =strlen(fullpath);

    for (int i = 0; i<fp_len;i++)
    {
    abs_path[i]=fullpath[i];
    }

    return true;
    }