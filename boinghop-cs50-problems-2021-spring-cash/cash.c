#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for Change owed
    float cash;
    do
    {
        cash = get_float("Cash owed:\n");
    }
    while (cash <= -1);
    
    //Round to the nearest penny and convert a float into an int
   {
       int coin = round(cash * 100);
       
        //Use largest amount of coins needed to return change owed
        int count = 0;
        
        while (coin > 0)
            //As many Quarters as possible
            {
            while (coin >= 25)
            {
                count ++;
                coin = coin - 25;
        
            }
            // As many Dimes
            while (coin >= 10)
            {
                count ++;
                coin = coin - 10;
        
            }
            // As many Nickles
            while (coin >= 5)
            {
                count ++;
                coin = coin - 5;
        
            }
            // As many Pennies
            while (coin >= 1)
            {
                count ++;
                coin = coin - 1;

    }
    }
    //Print the number of coins needed to give change owed
    printf("Total number of coins = %i\n", count);
}
}