#include <cs50.h>
#include <stdio.h>

void print_name(string name); /* clang trusts that it will encounter the definition of void after. */
/* This way you don't have to think about the actual order. */

int main(void)
{
    string s = get_string();
    print_name(s);
}

void print_name (string name)
{
    printf("hello, %s\n", name);
}
