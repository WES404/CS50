#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (1 > x || x > 8);

    for (int l = 0; l < x; l++ )
    {
        for (int c = 1; c <= ((x * 2) + 2); c++ )
        {
           if (c < (x - l) || (c <= (x + 2) && c > x) )
           {
               if (c > (x + 3 + l))
               {
                   continue;
               }
               else
               {
                   printf(" ");
               }
           }
           else
           {
               if ((c <= x && c >= (x - l)) || (c > (x + 2) && c <= (x + 3 + l)))
               {
                   printf("#");
               }
           }
        }
        printf("\n");
    }
}