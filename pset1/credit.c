#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int soma = 0;
    int soma1 = 0;
    int x = 0;
    long number = get_long("Credit Card Number: ");
    long y = number;
    while (number > 0)
    {
        int ult = number % 10;
        x++;
        if (x % 2 != 0)
        {
            soma += ult;
        }
        else
        {
            int mult = ult * 2;
            if (mult > 9)
            {
                soma1 += (mult % 10) + (mult / 10);
            }
            else
            {
                soma1 += mult;
            }
        }
        number = number / 10;
    }
    int total = soma1 + soma;
    int ultimo_digito = (total % 10);
    int z = y/(pow(10,15));
    int i = y/(pow(10,14));
    int w = y/(pow(10,12));
    int a = y/(pow(10,13));
    if ((ultimo_digito==0) && ((x==16) || (x==13)) && ((z == 4) || (w == 4)))
    {
        printf("VISA\n");
    }
    else
    {
        if ((ultimo_digito == 0) && (x == 15) && ((a== 34) || (a == 37)))
        {
            printf("AMEX\n");
        }
        else
        {
            if ((ultimo_digito == 0) && (x == 16) && ((i== 51) || (i== 52) || (i== 53) || (i== 54) || (i== 55)))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}