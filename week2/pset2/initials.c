#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

    printf ("Type your name:\n");
    string s = get_string();
    int i = 0;
    int n = strlen(s);
    
    
    for ( i = 0; i < n; i++)
    {
        if (i == 0)
        {
            char big = toupper(s[i]);
            printf("%c", big);
        }
        if (s[i] == ' ')
        {
            char big = toupper(s[i+1]);
            printf("%c", big);
        }
    }
    printf("\n");
    
}
