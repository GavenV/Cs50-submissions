#include <cs50>
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

int main()
{
    char candidates[MAX_CANDIDATES][256];
    int votes[MAX_CANDIDATES];
    int num_candidates;
    int num_voters;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++)
    {
        scanf("%s", candidates[i]);
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the votes:\n");
    for (int i = 0; i < num_voters; i++)
    {
        char vote[256];
        scanf("%s", vote);

        for (int j = 0; j < num_candidates; j++)
        {
            if (strcmp(vote, candidates[j]) == 0)
            {
                votes[j]++;
                break;
            }
        }
    }

    int winner = 0;
    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++)
    {
        if (votes[i] > max_votes)
        {
            max_votes = votes[i];
            winner = i;
        }
    }

    printf("The winner is: %s\n", candidates[winner]);

    return 0;
}
