#include <cs50.h>
#include <stdio.h>

int simga(int m);

int main (void);
{
    int n;
    do
    {
        printf("Positive integer please: ");
        n = get_int();
    
    }
    while (n < 1);
    // call a function sigma 
    //storing answer in answer
    int answer = sigma(n);
    
    // printing answer
    printf("%i\n", answer);
}

int sigma (int m)
{
    if (m <= 0)
    {
// return 0 if user does not cooperate
        return 0;
    }
    else
    {
//goal is to count all the numbers

        reutn (m + sigma (m - 1));
    }
}
