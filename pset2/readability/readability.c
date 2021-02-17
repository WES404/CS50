#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string x);
int count_words(string x);
int count_sentence(string x);

int main (void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentence(text);

    float L = (100 * letters) / words;
    float S = (100 * sentences) / words;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int x = (int) round(index);

    if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        if (x < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade %i\n", x);
        }
    }
}

int count_letters(string x)
{
    int count = 0;

    for (int i = 0; i < strlen(x); i++)
    {
        if (isalpha(x[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string x)
{
    int count = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (x[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentence(string x)
{
    int count = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (x[i] == '!' || x[i] == '?' || x[i] == '.')
        {
            count++;
        }
    }
    return count;
}