#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//create functions to count letters, words, and sentences
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    //get text from user
    string text = get_string("text: ");

    //initialize variables to recieve functions answers
    int let = count_letters(text);
    int word = count_words(text);
    int sent = count_sentences(text);

    //find value for letters per 100 words
    double L = ((double) let * 100 / (double) word);
    //find value for sentences per 100 words
    double S = ((double) sent * 100 / (double) word);

    //calculate Coleman-Liau index
    double score = (0.0588 * L - 0.296 * S - 15.8);
    int grade = round(score);

    //print grade with conditions
    if (grade >= 16)
    {

        printf("Grade 16+\n");

    }

    else if (grade < 1)
    {

        printf("Before Grade 1\n");

    }
    else
    {

        printf("Grade %i\n", grade);

    }


}

//define count letters function
int letters = 0;
int count_letters(string text)
{

    for (int i = 0; text[i] != '\0'; i++)
    {

        if (isalpha(text[i]))
        {

            letters ++;

        }


    }
    return letters;
}

//define count words function
int words = 0;
int count_words(string(text))
{

    for (int i = 0; text[i] != '\0'; i++)
    {

        if (isspace(text[i]))
        {

            words++;

        }
    }
    return (words + 1);

}

//define count sentences function
int sentences = 0;
int count_sentences(string(text))
{

    for (int i = 0; text[i] != '\0'; i++)
    {

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {

            sentences++;

        }

    }
    return sentences;

}



