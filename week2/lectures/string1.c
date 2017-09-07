#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // asks user for input
    printf("Type: ")
    string s = get_string();
    
    // makes sure get_string returned a string
    if (s != NULL)
    {
        // iterates the characters in s one at a time
        // better version. It's identical but not checking for lenght everytime
        //more optimal version
        for (int i = 0; n = strlen(s); i < n; i++)
        {
        //string is char* format, print w/ %c
            printf("%c\n", s[i]);
        }    
    }
}
