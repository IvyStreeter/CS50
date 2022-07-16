#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check command-line argument
    if (argc != 2 && !isdigit(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    //convert string to int 
    int k = atoi((argv[1])); 

    //get plain text and print 
    string p = get_string("plaintext: ");
    
    //cipher    
    //print cipher text
    printf("ciphertext: ");
    for (int i = 0, len = strlen(p); i < len; i++)
    {
        //alphabetical index
        if (isupper(p[i]))
        {
            printf("%c", 'A' + ((p[i]) - 'A' + k) % 26);
        }
        else if (islower(p[i]))
        {
            printf("%c", 'a' + ((p[i]) - 'a' + k) % 26);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    //print a space
    printf("\n");
    return 0;

}

