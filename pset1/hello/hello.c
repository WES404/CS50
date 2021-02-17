#include <stdio.h>
#include <cs50.h>

int main(void)

{
    string i = get_string("name: ");
    printf("Hello, %s\n", i);
}