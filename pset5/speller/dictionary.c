// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //hash word to find array index
    int hash_index = hash(word);
    
    //point curcor to start of node
    node *cursor = table[hash_index];
    
    //iterate through words to see if its in the dictionary
    while (cursor != NULL)
    {
        //ignore case when comparing words
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //adapted by Neel Mehta from http://stackoverflow.com/questions/2571683/djb2-hash-function.
    unsigned long hash = 5381;
    
    for (const char *ptr = word; *ptr != '\0'; ptr++)
    {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //create pointer to a file to read
    FILE *file = fopen(dictionary, "r");
    
    //check to see if pointer exists
    if (file == NULL)
    {
        return false;
    }

    char new_word[LENGTH + 1];
    
    //scan through words to load from dictionaries until end of file
    while (fscanf(file, "%s", new_word) != EOF)
    {
        //create new node for storing words
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        
        //copy word to be hashed for the index value
        strcpy(n->word, new_word);
        int hash_index = hash(new_word);
        n->next = table[hash_index];
        table[hash_index] = n;
        
        //keep track of the number of words in dictionary
        word_count++;
    }
    fclose(file);
    return true;
    
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //return number of words found in load function
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //iterate through each bucket in hash table
    for (int i = 0; i < N; i++)
    {
        //create pointer to node to keep track of each node
        node *cursor = table[i];
        
        while (cursor != NULL)
        {
            //create another temp node to make sure not to abandon any nodes in memory
            node *temp = cursor;
            cursor = cursor->next;
            //free any allocated memory
            free(temp);
        }
        
        if (cursor == NULL && i == (N - 1))
        {
            return true;
        }
    }
    return false;
}
