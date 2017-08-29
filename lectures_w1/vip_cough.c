/* pre-processing*/
#include <cs50.h>
#include <stdio.h>
/*When you compile your code you get assembly language*/
/* opening cough.s--> It's on assembly language */
/* Linking: Hey computer, take all 01s from all programs and combine them*/
void say(string s, int n); 
void cough(int n); 
void sneeze(int n); 

int main(void)
{
    cough(3);
    sneeze(3);
}

void say(string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", s);
    }
        
}

void cough(int n)
{
    say("cough", n);
}

void sneeze(int n)
{
    say("achuu", n);
}

