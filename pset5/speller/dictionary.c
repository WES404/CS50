// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26 * 26 * 26;

//Contagem de palavras
unsigned int palavras;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // encontra o index da palavra
    int index = hash(word);

    // Abre lista de hash dentro da tabela no index encontrado
    node *cursor = table[index];

    while (cursor != NULL)
    {
        //procura se a palavra está na lista linkada
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
    // Adaptation of Dan Bernstein's djb2

    unsigned long hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */ // Move hash 5 bit para a esquerda
    }
    return hash % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE *dic = fopen(dictionary, "r");

    if (dic == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(dic, "%s", word) != EOF) //Para quando atingir o final do arquivo
    {

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, word); // Palavra é colocada no node


        int index = hash(word); // Devolve o index da palavra na tabela

        // o pointer aponta para a tabela (sendo a primeira vez ela está vazia)
        // Na segunda a nova palavra aponta para a primeira da lista na tabela
        n -> next = table[index];

        // tabela aponta para o novo nó (no primeiro caso é o proprio nó)
        table[index] = n;

        palavras++;
    }

    fclose(dic);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return palavras;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *posicao = table[i];

        while (posicao)
        {
            // Cria e libera o temporario
            node * temporario = posicao;
            posicao = posicao -> next;
            free(temporario);
        }

        if (i == N - 1 && posicao == NULL)
        {
            // Quando chega no final do N e quando a proxima posicao não existe, tudo foi liberado
            return true;
        }
    }
    return false;
}
