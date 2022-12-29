#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{

    long cc;
    do
    {

        cc = get_long("Number:\n");

    }
    while (cc < 999999999999 || cc > 9999999999999999);

    long digits = cc;
    int count = 0;
    do
    {
        digits /= 10;
        count++;
    }
    while (digits > 0);
    printf("%i\n", count);
    return count;

    long num = cc;
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;

    while (num > 0)
    {
        int otherNum = num % 10;
        sum2 = (sum2 + otherNum);
        printf("%i\n", sum2);
        num = num / 10;
        int skipNumber = num % 10;
        sum1 = sum1 + (skipNumber * 2);
        printf("%i\n", sum1);
        num = num / 10;
    }
    total = sum1 + sum2;
    printf("%i\n", total);
    
    if ((total % 10) != 0)
    {
        printf("INVALID");
        return 0;
    }
    if ((total % 10) == 0)
    {
        while (num >= 10)
        {
            num = num / 10;
        }
        
        if (num == 4 && (count == 13 || count == 16))
        {
            printf("VISA");
        }
        
    }










}