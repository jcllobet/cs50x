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
    int sum = 0;
    for (int i = 1; i <=m; i++)
    {
        sum += i;
    }
    return sum;
}
