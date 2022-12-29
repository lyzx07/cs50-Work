#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    
    //find out if 2 arguments and that argv is a digit
    if (argc == 2 && isdigit(*argv[1]))
    {
        
        //change string to int
        int k = atoi(argv[1]);
        //get plain text before encryption
        string before = get_string("plain text: ");
        
        //print encrypted code word
        printf("ciphertext: ");
        
        
        //iterate through entire word and change according to key
        for (int i = 0, n = strlen(before); i < n; i++)
        {
            
            //if lowercase
            if (before[i] >= 'a' && before[i] <= 'z')
            {
                
                printf("%c", (((before[i] - 'a') + k) % 26 + 'a'));
                
            }
            
            //if uppercase
            else if (before[i] >= 'A' && before[i] <= 'Z')
            {
                
                printf("%c", (((before[i] - 'A') + k) % 26 + 'A'));
                
            }
            
            //all other characters don't get changed
            else
            {
                
                printf("%c", before[i]);
                
            }
            
            
        }
        //print new line and return 0
        printf("\n");
        return 0;

    }
    else 
    {
        
        //print if not 2 arguements or not a number
        printf("Usage: ./caesar key\n");
        return 1;
        
    }
    
}
   
