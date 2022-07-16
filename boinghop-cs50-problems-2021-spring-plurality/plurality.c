#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates - constant
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
    // TODO - if the name recieved is on the list
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // increment by one
            candidates[i].votes++;

            // successful ballot therefore, does not run loop for invalid vote
            return true;
        }
    }
    // otherwise invalid ballot, loop through the invalid vote
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO - set winner as first candidate
    int winner = candidates[0].votes;

    // iterate over candidates to determine the winner
    for (int i = 0; candidate_count > i; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }
    // iterate over the candidates to name the winner with the highest votes
    for (int j = 0; candidate_count > j; j++)
        {
            if (candidates[j].votes == winner)
            {
                // print winner
                printf("%s\n", candidates[j].name);
            }
        }
        return;
}

