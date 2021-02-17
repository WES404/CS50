#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checagem(string x[]);
string codificando(string texto, string x[]);

int main(int argc, string x[])
{
    int termo = checagem(x);

    if (termo == 1)
    {
        return 1;
    }

    string texto = get_string("PlainText: ");
    string ciphertext = codificando(texto, x);

    printf("ciphertext: %s\n", ciphertext);
}

int checagem(string key[])
{
    string x = (string) key[1];
    int tam = strlen(x);

    if (tam < 1)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    if (tam < 26 || tam > 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            for (int h = 0; h < 26; h++)
            {
                if(i == 0)
                {
                    if (isdigit(x[h]))
                    {
                        printf("Key must only contain alphabetic characters.");
                        return 1;
                    }
                }

                if (i != h)
                {
                    if (x[i] == x[h])
                    {
                        printf("Key must contain different characters.");
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
}

string codificando(string texto, string key[])
{
    static char Cypher[] = " ";
    int index = 0;
    char aux;
    string x = (string) key[1];

    char alfaupper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alfalower[26] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < strlen(texto); i++)
    {
        if (isdigit(texto[i]))
        {
            aux = (int) texto[i];
            strncat(Cypher, &aux, 1);
            continue;
        }
        for (int h = 0; h < strlen((string) x); h++)
        {
            if (texto[i] == alfaupper[h] || texto[i] == alfalower[h])
            {
                index = h;
                break;
            }
        }
        if (isalpha(texto[i]))
        {
            if (isupper(texto[i]))
            {
                aux = toupper(x[index]);
                strncat(Cypher, &aux, 1);
            }

            else
            {
                aux = tolower(x[index]);
                strncat(Cypher, &aux, 1);
            }
        }
        else
        {

            aux = texto[i];
            strncat(Cypher, &aux, 1);
        }
    }
    return Cypher;
}