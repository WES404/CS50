// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int palavras = 0;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = table;

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");

    if (dic == NULL)
    {
        return false;
    }

    char word[45];
    int prim = 0;
    node *list = malloc(sizeof(node));

    while (fscanf(dic, "%s", word) != EOF) //Para quando
    {
        fscanf(dic, "%s", word);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, word);

        int ind = hash(word); //envia palavra para função hash e devolve index

        if (prim == 0)
        {
            n -> next = NULL;
            table[ind] = n; // determina o point para proxima palavra
            list = n; // Se primeiva vez m == table
            prim++;
        }
        else
        {

            n -> next = NULL;
            table[ind] = n;// determina o point para proxima palavra
            list -> next = n; // se segunda vez table aponta pro proximo n
        }
        palavras++;
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return palavras;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = malloc(sizeof(node));
    node *tmp = malloc(sizeof(node));
    cursor = table;

    while (cursor != NULL)
    {
        tmp = cursor;
        free(tmp);
        if (tmp != NULL)
        {
            return false;
        }
        cursor = cursor -> next;
    }
    return true;
}
