#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int aux = 0;
    int index1 = 0;
    int index2 = 0;
    bool igual;
    int count = 0;
    bool feito = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidate_count > 2 && !feito) // compara todos os numeros e conta
        {
            for (int h = 1; h < candidate_count; h++)
            {
                if (candidates[i].votes == candidates[h].votes)
                {
                    count++;
                }
            }
            count++;
            feito = true;
        }
        if (count == candidate_count) //Se todos empataram printa todos
        {
            for (int j = 0; j < candidate_count; j++)
            {
                printf("%s\n", candidates[j].name);
            }
            return;
        }
        if (candidates[i].votes > aux) //se maior que o aux é o mais votado
        {
            index1 = i;
            aux = candidates[i].votes;
        }

        else
        {
            if (candidates[i].votes == aux) //Se igual a aux é empate
            {
                aux = candidates[i].votes;
                index2 = i;
                igual = true;
            }
        }
    }
    if (igual && candidates[index1].votes == candidates[index2].votes)
    {
        printf("%s\n", candidates[index1].name);
        printf("%s\n", candidates[index2].name);
    }
    else
    {
        printf("%s\n", candidates[index1].name);
    }
    return;
}

