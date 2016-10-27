#include <stdio.h>
#include <cs50.h>

int main(void)
{
  string menuItems[] = {"Water", "Soda", "Cheeseburger", "Fries"};

  // Display menu:
  printf("Welcome to Good Burger! Can I take your order?\n");
  printf("MENU:\n");
  for (int i = 0; i < 4; i++)
  {
    printf("Item %i: %s\n", i, menuItems[i]);
  }
  printf("\nHow many items?\n");

  int numItems = GetInt();

  // PUT YOUR CODE HERE: open a file to write
FILE* menu;
menu = fopen("menu_items.txt","w");
  // PUT YOUR CODE HERE: before continuing, make sure the file pointer is not NULL
if (menu != NULL)
{
   


  // if it is NULL, then quit the program (return 1) instead of continuing

  for (int i = 0; i < numItems; i++)
  {
    printf("Which menu item would you like?\n");
    // PUT YOUR CODE HERE: Take the order number, translate it into an item, and write the item to the file
    int item = GetInt();
    if (item == 0)
    {
        fprintf(menu,"Water");
    }
        if (item == 1)
    {
        fprintf(menu,"Soda");
    }
        if (item == 2)
    {
        fprintf(menu,"Cheeseburgers");
    }
        if (item == 3)
    {
        fprintf(menu,"Fries");
    }


    
    
    // PUT YOUR CODE HERE: Write a new line ("\n") to the file 
    fprintf(menu,"\n");
  }

  // PUT YOUR CODE HERE: close the file
  fclose(menu);
}
return 1;
}