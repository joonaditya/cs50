// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
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

int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    int hash_value = hash(word);

    node *n = table[hash_value];

    while(n != NULL)
    {
        if(strcasecmp(word, n -> word) == 0)
        {
            return true;
        }

        n = n -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO

    long sum = 0;

    for(int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *dict_pointer = fopen(dictionary, "r");

    if(dictionary == NULL){
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    char next_word[LENGTH + 1];

    while(fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }

        strcpy(newNode -> word, next_word);

        int hash_value = hash(next_word);

        newNode -> next = table[hash_value];
        table[hash_value] = newNode;
        dict_size++;
    }

    fclose(dict_pointer);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for(int i = 0; i < N; i ++)
    {
        node *n = table[i];

        while(n != NULL)
        {
            node *tmp = n;
            n = n -> next;
            free(tmp);
        }

        if(n == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;
}
