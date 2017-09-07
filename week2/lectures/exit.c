#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1; // its just exit code. Useful for the programmer or company. Not relevant to the machine
    }
    
    printf("hello, %s\n", argv[1]);
    return 0;
    
}
