#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //declaring variables
    int letters = 0;
    int words = 1;
    int sentence_count = 0;

    //taking input
    string text = get_string("Text: ");

    //finding number of letter
    for (int i = 0; i < strlen(text); i++)
    {
       if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
       {
           letters++;
       }
       else if (text[i] == ' ')
       {
           words++;
       }
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
       {
           sentence_count++;
       }
    }

    //finding grade
    float grade = 0.0588 * (100*(float)letters/(float)words) - 0.296 * (100*(float)sentence_count/(float)words) - 15.8;
    grade = round(grade); //rounding of the deciman value to the nearest integer
    if (grade < 16 && grade >= 0){
        printf("Grade %i\n", (int) grade);
    }
    else if (grade >= 16){
        printf("Grade 16+\n");
    }
    else {
        printf("Before Grade 1\n");
    }
}
