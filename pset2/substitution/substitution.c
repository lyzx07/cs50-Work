#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check to make sure there is only one command line argyment
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    //check to make sure argv[1] has 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    
    //check tom= make sure argv[1] has only alphabet characters
    for (int i = 0; i < 26; i++)
    {
        if (! isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
    }
    
    //check to make sure argv[1] has no repeated characters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    string key = argv[1];
    //print plaintext to have user input a text to be ciphered
    string plain = get_string("plaintext:");
    string New = plain;
    printf("ciphertext:");
    //create array of regular alphabet
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    
    //iterate through plaintext word to change each letter
    for (int i = 0; i < strlen(plain); i++)
    {
        //if lowercase
        if (islower(plain[i]))
        {
            for (int j = 0; j < strlen(alpha); j++)
            {
                if (plain[i] == alpha[j])
                {
                    New[i] = key[j];
                    printf("%c", tolower(New[i]));
                    j = 0;
                    break;
                }
            }
            
        }
        else if (isupper(plain[i]))
        {
            for (int j = 0; j < strlen(alpha); j++)
            {
                if (plain[i] == toupper(alpha[j]))
                {
                    New[i] = toupper(key[j]);
                    printf("%c", New[i]);
                    j = 0;
                    break;
                }
            }
            
        }
        else
        {
            printf("%c", New[i]);
        }

    }
    //print new line
    printf("\n");
    return 0;

}



