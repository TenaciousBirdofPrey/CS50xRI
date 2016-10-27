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



bool parse(const char* line);

int main (void)
{
   
     const char* line = "GET / HTTP/1.1";
    while (parse(line)==false)
    {
        printf("hi\n");
    }
    
}

bool parse(const char* line)
{

   if (strchr(line,'?') != NULL)
   {
       printf(" there is a question\n");
       return true;
   }
   else
   {
       printf("there is no question mark\n");
       return true;
   }
   
   return false;

}