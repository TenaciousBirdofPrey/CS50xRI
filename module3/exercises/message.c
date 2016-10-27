#include <stdio.h>
#include <cs50.h>

/**
 * Prints a personalized message to the console.
 */
int main(void)

{
 void printMessage (string sender, string recipient, string message);
 
  
  printf("Name of sender: ");
  string sender = GetString();

  printf("Name of recipient: ");
  string recipient = GetString();

  printf("Message: ");
  string message = GetString();

  printMessage(sender, recipient, message);
}

// TODO create a function called printMessage
void printMessage (string sender, string recipient, string message)
{
  printf(" Dear %s\n \n %s\n Sincerely\n %s\n", recipient, message, sender);
}