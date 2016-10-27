/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{//start search
//2 *4 6 8 10 12 14 16 18
//0  1 2 3 4  5   6  7  8

int start = 0;
int end = n-1;
int middle = (end-start)/2;
if (value < 0)
{
    return false;
}
do 
{
    //printf("to begind. start is %i,end is %i and middle is %i\n\n",start,end,middle);
    if(values[middle] == value)
    {
    return true;
    }

    if(values[middle]<value)
    {
    start =  middle + 1;
    middle = (end+start)/2;
    //printf("the values[middle] is: %i\n and less then value %i \n start is %i and end is %i\n",values[middle],value, start,end);
    }

    if (values[middle]>value)
    {
    end = middle -1;
    middle = (end-start)/2;
   // printf("the values[middle] is: %i\n and greater then value %i \n start is %i and end is %i\n",values[middle],value, start,end);
    }

}
while(end >= start);

return false;
}





/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{//start sort

/*testing pre-sort
for (int i=0; i<n-1;i++)
{
    printf("pre = %i\n",values[i]);
}
*/
   int bubbler;
   do
   {//start do
   int i;
   bubbler = 0;
   for (i=0;i<n-1;i++)
   {// start for

      if (values[i]> values[i+1] )
      {// start if
         int swapem;
         swapem = values[i+1];
         values[i+1] = values[i];
         values[i] =swapem;
         bubbler = bubbler + 1;
      }// end if
      
   }//end for
       
   }// end do
   while (bubbler > 0);


/*testing post sort
for (int i=0; i<n-1;i++)
{
    printf("[%i]%i\n",i,values[i]);
}

    printf("hello sort is accessed");
*/

    return;
}//end sort