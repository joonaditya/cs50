#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // asks the user their name and then store it in a variable, which is later on used to greet the user
    string name = get_string("What's your name? \n");
    printf("Hello, %s\n", name);
}
