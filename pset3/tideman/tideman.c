#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int pesos[candidate_count];

    for (int j = 0; j < candidate_count; j++) //Distribui o peso da escolha
    {
        int num = ranks[j];
        pesos[num] = candidate_count - j; //o primeiro index recebe o maior peso
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int h = 0; h < candidate_count; h++)
        {
            if (i == h)
            {
                preferences[i][h] = 0;
                continue;
            }

            if (pesos[i] > pesos[h])
            {
                preferences[i][h]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int aux = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int h = 0; h < candidate_count; h++)
        {
            if (i >= h) //Se i for menor que ou igual a h não será computado
            { //Assim, só procisa computar o triangulo superior da matriz
                continue;
            }

            int num1 = preferences[i][h];
            int num2 = preferences[h][i];

            if (num1 > num2)
            {
                pair_count++;
                pairs[aux].winner = i;
                pairs[aux].loser = h;
            }
            else
            {
                if (num1 < num2)
                {
                    pair_count++;
                    pairs[aux].winner = h;
                    pairs[aux].loser = i;
                }
            }
            aux++;
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int aux1, aux2, aux3, aux4, num1, num2;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        aux1 = pairs[i].winner;
        aux2 = pairs[i].loser;
        aux3 = pairs[i + 1].winner;
        aux4 = pairs[i + 1].loser;

        num1 = preferences[aux1][aux2];
        num2 = preferences[aux3][aux4];

        if (num1 < num2)
        {
            pairs[i].winner = aux3;
            pairs[i+1].winner = aux1;
            pairs[i].loser = aux4;
            pairs[i+1].loser = aux2;
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void) //ERROR
{
    for (int i = 0; i < candidate_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        locked[pairs[i].loser][pairs[i].winner] = false;
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int count[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        for (int h = 0; h < candidate_count; h++)
        {
            if (locked[i][h]) //se index em locked for True é somado no count
            {
                count[i]++;
            }
        }
    } //No final o index com maior número de True é o vencedor

    int maior = 0;
    int index;
    for (int j = 0; j < candidate_count; j++)
    {
        if (count[j] > maior) //Procura o maior count
        {
            index = j;
            maior = count[j];
        }
    }
    printf("%s\n", candidates[index]);
    return;
}

