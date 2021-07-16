#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Enter a number between 1 and 8: \n");
    }
    while (number < 1 || number > 8);

    for (int height = 0; height < number; height++)
    {
        for (int spaces = number - height - 2; spaces >= 0; spaces--) //printing spaces before pyramid
        {
            printf(" ");
        }
        for (int row = 0; row <= height; row++) //left pyramid
        {
            printf("#");
        }
        printf("  ");
        for (int row2 = 0; row2 <= height; row2++) //right pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}
