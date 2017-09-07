#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Type")
    string s = get_string();
    if (s != NULL)
    {
        for (int i = 0; i < strlen(s); i++)
        {
        //string is char* format, print w/ %c
            printf("%c\n", s[i]);
        }    
    }
}
