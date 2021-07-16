#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int pyramid;
    do
    {
        pyramid = get_int("Enter a number between 0 and 9: \n");//taking the input
    }
    while (pyramid < 1 || pyramid > 8);//making sure that the number entered is between 1 and 8
    int i;//declaring i
    for (i = 0; pyramid > i; i++)
    {
        for (int j = 0; pyramid > j; j++)
        {
            if (i + j < pyramid - 1)
            {
                printf(" ");//printing the spaces
            }
            else
            {
                printf("#");//printing the hashes
            }
        }
        printf("\n");//printing a new line
    }
}
