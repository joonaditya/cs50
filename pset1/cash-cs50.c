#include <stdio.h>
#include <cs50.h>
#include <math.h> //importing math file

int main(void)
{
    float balance; //declaring the float variable named as balance

    do
    {
        balance = get_float("Change owed: ");
    }
    while (balance <= 0); //checking if the balance provided is bigger than 0 or not, and if not asking for the input again

    int cents = round(balance * 100); //rounding the cents to the nearest penny using round
    int coins = 0; //declaring the interger variable named as coins

    while (cents >= 25)//checking if cents is greater than or equals to 25, if yes then subtracting 25
    {
        cents -= 25;
        coins++;//increasing the number of coins
    }
    while (cents >= 10)//checking if cents is greater than or equals to 10, if yes then subtracting 10
    {
        cents -= 10;
        coins++;
    }
    while (cents >= 5)//checking if cents is greater than or equals to 5, if yes then subtracting 5
    {
        cents -= 5;
        coins++;
    }
    while (cents >= 1)//checking if cents is greater than or equals to 1, if yes then subtracting 1
    {
        cents -= 1;
        coins++;
    }
    printf("%i\n", coins);//printing the result
}
