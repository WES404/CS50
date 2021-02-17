#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int tamanho_inicial = get_int("Start size: ");
    while (tamanho_inicial < 9)
    { // O tamanho inicial deve ser maior que 9
        tamanho_inicial = get_int("Start size: ");
    }

    int tamanho_final = get_int("End size: ");
    while (tamanho_final < tamanho_inicial)
    { // O tamanho final tem que ser maior que o inicial
        tamanho_final = get_int("End size: ");
    }

    int anos = 0;
    int populacao = tamanho_inicial;


    while (populacao < tamanho_final)
    { // Conta o numero de anos apartir da aproximidade da população com o tamanho_final
        int nascidos = populacao / 3;
        int mortos = populacao / 4;

        populacao += nascidos - mortos;
        anos++;
    }

    printf("Years: %i\n", anos);
}