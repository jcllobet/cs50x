#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //single quotes matter (char)
    for (char c = 'A'; c <= 'Z'; c++)
    {
        printf("%c is %i\n", c, (int) c);
    }
}
