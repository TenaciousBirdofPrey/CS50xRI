/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include<string.h>
# include <ctype.h>

// declare struct node
typedef struct node
{
    char word[47];
    struct node* next;
} node;

// GLOBAL VARIABLES
node* HASHTABLE[28];
int SIZE;




/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
  
    char copy_word [LENGTH+1];
    int x = strlen(word);
    
    for (int i=0;i<x;i++)
    {
    copy_word[i]=tolower(word[i]);
    } 
    
    copy_word[x]='\0';
    
    int hash = hash_it(copy_word);
   
    node* cursor =HASHTABLE[hash];
    if (HASHTABLE[hash]==NULL)
    {
        return false;
    }
                                
    while (cursor != NULL)
    {
        //int comp = strcmp(copy_word,cursor->word);
        //printf("copy:%s\n",copy_word);
        //printf("cursor:%s\n",cursor->word);
        //printf("result:%i\n",comp);
        if (strcmp(copy_word,cursor->word)==0)   
        {                                     
             return true;                     
        }
        cursor = cursor->next;
        
    }
 
    return false;
}






/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    
   // creat a pointer to file, malloc buffer and open dictionary
    FILE* file;
   
    file = fopen(dictionary,"r");
    
   // test if dict exists
    if (file == NULL)
    {
        printf("no dict!\n");
        return false;
    }
     // create an array that holds chars
    char line[LENGTH+1];
    
  
    for (int i =0; i<28;i++)
    {
        HASHTABLE[i] = NULL;
    }
  


    //loop throu dict
    while ( fscanf(file,"%s\n" , line) != EOF   )
    {
        node* newnode = malloc(sizeof(node));
        
        //newnode->word=line;
        //printf("line is %s in node is %s\n",line,newnode->word);
        
        strcpy(newnode->word, line);//-----------------------------------------
        
       int line_hashed = hash_it(line);
        
     if (HASHTABLE[line_hashed]==NULL)
        {

         HASHTABLE[line_hashed] = newnode;
         
         newnode->next = NULL;

         SIZE ++;
        
        }
            
        
      
        
        else
        {
            

        newnode->next =HASHTABLE[line_hashed];
        
        HASHTABLE[line_hashed]=newnode;
         
        
        SIZE++;
        }


    }
 
    fclose(file);
    
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return SIZE;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    
    for(int i = 0; i < 28; i++)
    {
        node* cursor = HASHTABLE[i];
         while (cursor != NULL)
        {
        node* temp = cursor;
        cursor = cursor->next;
        free(temp);
        }
    }
    return true;
}

//HASH FUNCTION
//https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
//https://www.reddit.com/user/delipity


int hash_it(char* needs_hashing)
{
 int hash = needs_hashing[0];
   
    return hash%26;





/*int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % 6;
}


*/
}