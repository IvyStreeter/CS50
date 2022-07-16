// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

// arbitrary number of buckets in hash table
const unsigned int N = 10000;

// size counter
unsigned int SIZE = 0;

// Hash table
node *table[N];

// hash function
// https://gist.github.com/MohamedTaha98/ccdf734f13299efb73ff0b12f7ce429f
// adapted here https://github.com/hathix/cs50-section/blob/master/code/7/sample-hash-functions/good-hash-function.c
// altered the type of hash in dictrionary.h
unsigned int hash(const char *word) 
{
    unsigned int hash = 5381;
    for (const char* ptr = word; *ptr != '\0'; ptr++)
    {
        //tweaked to toupper made the function faster
        hash = ((hash << 5) + hash) + toupper(*ptr);
    }
        return (hash % N);
}
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int i = hash(word);
    node *ptr = table[i];
    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open a dictionary file
    FILE *file = fopen (dictionary, "r");
    if (!file)
    {
        return false;
    }
    //buffer
    char word[LENGTH + 1];
    
    //read strings from file one at a time
    while (fscanf (file, "%s", word) != EOF)
    {
        //count words
        SIZE++;
        
        //create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        
        // copy word into node
        strcpy (n->word, word);
        n->next = NULL;
        
        // insert node into hash table at that location
        int i = hash(word);

        if (table[i] == NULL)
        {
            table[i] = n;
        }
        // if something in node, go to next node
        else
        {
            n->next = table[i];
            table[i] = n;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return SIZE;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *ptr1 = table[i];
        node *ptr2 = table[i];
        
        while(ptr2 != NULL)
        {
            ptr2 = ptr2->next;
            free(ptr1);
            ptr1 = ptr2;
        }
        table[i] = NULL;
    }
    return true;
}
