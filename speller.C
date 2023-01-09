#include <cs50>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 1000000

typedef struct node
{
    char word[46];
    struct node *next;
}
node;

node *hash_table[HASH_SIZE];

// djb2 hash function
unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % HASH_SIZE;
}

void load(char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary.\n");
        exit(1);
    }

    char word[46];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not allocate memory for new node.\n");
            exit(2);
        }

        strcpy(new_node->word, word);

        unsigned long index = hash(word);
        new_node->next = hash_table[index];
        hash_table[index] = new_node;
    }

    fclose(file);
}

bool check(char *word)
{
    node *cursor = hash_table[hash(word)];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

void unload(void)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        node *cursor = hash_table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 3)
    {
        printf("Usage: spellcheck dictionary [file]\n");
        return 1;
    }

    char *dictionary = argv[1];
    load(dictionary);

    if (argc == 3)
    {
        char *file = argv[2];
        FILE *inptr = fopen(file, "r");
        if (inptr == NULL)
        {
            printf("Could not open %s.\n", file);
            return 2;
        }

        char c;
        int index = 0;
        char word[46];
        while ((c = fgetc(inptr)) != EOF)
        {
            if (isalpha(c) || c == '
