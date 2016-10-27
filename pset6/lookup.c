#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

char* lookup(char*);

int main (void)
{
    char* pather = "home/ubuntu/workspace/pset6/index.JPG";
    printf("%s\n", lookup(pather));
}


char* lookup (char* path)
{
    char* target = strrchr(path,'.');
    
    if (strcasecmp(target,".css")==0)
    {
    return "text/css";
    }
    
        if (strcasecmp(target,".html")==0)
    {
    return "text/html";
    }
    
        if (strcasecmp(target,".gif")==0)
    {
    return "image/gif";
    }
    
        if (strcasecmp(target,".ico")==0)
    {
    return "image/x-icon";
    }
    
        if (strcasecmp(target,".jpg")==0)
    {
    return "image/jpeg";
    }
    
        if (strcasecmp(target,".js")==0)
    {
    return "text/javascript";
    }
    
        if (strcasecmp(target,".php")==0)
    {
    return "text/x-php";
    }
    
    if (strcasecmp(target,".png")==0)
    {
    return "image/png";
    }
    
    
return NULL;
}




