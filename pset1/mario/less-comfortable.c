#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int pyramid;//input from user
    do
    {
        pyramid = get_int("Enter a number between 0 and 9: \n");
    }
    while (pyramid < 1 || pyramid > 8);
    int i;
    for (i = 0; pyramid > i; i++)
    {
        for (int j = 0; pyramid > j; j++)
        {
            if (i + j < pyramid - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
