#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    for (int i = 65; i < 65 + 26; i++)
    {
        // converting integer to a char
        printf("%c is %i\n", (char) i, i);
    }
}
