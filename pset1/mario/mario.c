#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //initialize variable
    int n;
    //ask for height from user until given a number between 1-8 
    do
    {

        n = get_int("Height of pyramid? ");

    }
    while (n < 1 || n > 8);

    //print first half of pyramid with spaces only
    for (int x = 0; x < n; x++)
    {
        for (int s = n - x; s > 1; s--)
        {

            printf(" ");

        }
        //print first half of pyramid with hashes
        for (int h = n + x + 1; h > n; h--)
        {

            printf("#");

        }
        //print spaces inbetween the two pyramids
        printf("  ");
        //print second half of pyramid with hashes
        for (int y = 0; y < x; y++)
        {

            printf("#");

        }
        printf("#\n");
    }








}