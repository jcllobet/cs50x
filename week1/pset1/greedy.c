#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Variable declarations
    float given_amount = 0;
    int cent_amount = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int leftover = 0;
    int coin_count = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    
    do
    {
    printf("Input your change:");
    given_amount = get_float();

    }
    
    while (given_amount <= 0);
    
    // Given amount is convert to cents
    cent_amount = (int)round(given_amount*100); 
    
    quarter_count = cent_amount / quarter;
    leftover = cent_amount % quarter;

    dime_count = leftover / dime;
    leftover = leftover % dime; 

    nickel_count = leftover / nickel; 
    leftover = leftover % nickel; 

    
    coin_count = quarter_count + dime_count + nickel_count + leftover; //pennies at this point

    printf("%i\n", coin_count);    
        
    return 0;


    
}
