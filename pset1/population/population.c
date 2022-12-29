#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int d;
    int s;
    int e;
    int n;
    int y;
    
    do
    {
        // TODO: Prompt for start size
        s = get_int("Start size: ");
      
    }
    while (s < 9);
    
    
    
    do 
    {
        // TODO: Prompt for end size
        e = get_int("End size: ");
        
    }
    while (e < s);
    
    for (y = 0; s < e; y++)
    {
        
        n = s / 3;
        d = s / 4;
        s = s + n - d;
        // TODO: Calculate number of years to reach threshold
    }   
    
    {
        // TODO: Print number of years
        printf("Years: %i\n", (int) y);
    }
    
    return 0;
    
}
