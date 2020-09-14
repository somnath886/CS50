// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define N 27

// Represents a trie

typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

node *root;
unsigned long words = 0;
node *create_node();
void triefree(node *r);
// Loads dictionary into memory, returning true if successful else false

bool load(const char *dictionary)
{
    // Initialize trie

    root = create_node();

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    node *n = root;

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        for (int i = 0; i <= strlen(word); i++)
        {
            int h = hash(word[i]);

            if (word[i] != '\0')
            {
                if (n->children[h] == NULL)
                {
                    n->children[h] = create_node();
                }
                n = n->children[h];
            }

            else if (word[i] == '\0')
            {
                n->is_word = true;
                words++;
                n = root;
            }
        }

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *n = root;

    for (int i = 0; i <= strlen(word);  i++)
    {
        int h = hash(word[i]);

        if (word[i] == '\0')
        {
            if (n->is_word == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if (n->children[h] == NULL)
        {
            return false;
        }

        n = n->children[h];

    }

    if (!n)
    {
        return false;
    }

    return n->is_word;
}

void triefree(node *r)
{
    for (int i = 0; i < N; i++)
    {
        if (r->children[i] != NULL)
        {
            triefree(r->children[i]);
        }
    }

    free(r);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    triefree(root);
    return true;
}

int hash(const char word)
{
    if (word == '\'')
    {
        return N - 1;
    }

    return tolower(word) - 97;
}

node *create_node()
{
    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return false;
    }
    n->is_word = false;
    for (int i = 0; i < N; i++)
    {
        n->children[i] = NULL;
    }

    return n;
}
