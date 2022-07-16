#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int compute_word (string word);

int main(void)

{
    //prompt user for a string of text
    string text = get_string ("Text: ");
    int letter = 0, word = 1, sentence = 0;
    {
        //iterate over the text
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            //increment L for any letter regardless of case
            if ((isupper(text[i])) || (islower(text[i])))
                {
                    letter++;
                }
            //increment W for any space, W is set to 1 to account for the last word
            if ((isspace(text[i])))
                {
                    word++;
                }
            //increment S for these specific punctuation
            if ((text[i] == '.' || text[i] == '!' || text[i] == '?'))
                {
                    sentence++;
                }
        }
    }
        //print letters, words, sentences
        // printf("Letter(s): %i\nWord(s): %i\nSentence(s): %i\n", letter, word, sentence);
       float L = (letter / (float) word) * 100;
       float S = (sentence / (float) word) * 100;
       
       int index = round(0.0588 * L - 0.296 * S - 15.8);
        {
            if (index < 1)
            {
                printf ("Before Grade 1\n");
            }
            else if (index > 16)
            {
                printf("Grade 16+\n");
            }
            else
            {
                printf("Grade %i\n", index);
            }
        }
    }

