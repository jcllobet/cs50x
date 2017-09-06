#include <stdio.h>
#include <cs50.h>
//i need to tell the compiler what this functions are
//filename to include string cs50.h

int main(void)
{
    string s = get_string();
    printf("hello, %s\n", s);
}
