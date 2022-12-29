#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    float c;
    do
    {
        //get owed change from user
        c = get_float("Change owed?\n");
    }
    while (c < 0.00);
    
    //round change to nearest penny and change from float to int
    int change = round(c * 100);
    int coins = 0;
    
    //calculate how many coins to give back to user
    while (change >= 25)
    {
        change = change - 25;
        coins++;
    }
    
    while (change >= 10)
    {
        change = change - 10;
        coins++;
    }
    
    while (change >= 5)
    {
        change = change - 5;
        coins++;
    }
    
    while (change >= 1)
    {
        change --;
        coins++;
    }
    //print amount of coins user will recieve back
    printf("Coins back: %i\n", coins);
}   


    
        
    
    
    
    
    
    
    
    
    
    
    
    
