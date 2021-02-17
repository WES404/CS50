#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long y = get_long("numero;");
    int x = (y / (pow(10, 15)));
    printf("x : %d\n", x);
}