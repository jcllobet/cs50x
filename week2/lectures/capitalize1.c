#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//more efficient function. More optimal etc. 
int main(void)
{
    string s = get_string();
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                //or 32 = 'a' - 'A'
                printf("%c", toupper(s[i]));
            }
            else 
            {
                printf("%c", s[i]);
            }
        }
    }
    printf("\n");
}
