#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//assigning values that we care about outside of main so they are not hardcoded
#define BUFFER_SIZE 512
#define FILENAME 8

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc !=2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE* outfile = NULL;
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }
    
    bool jpeg = false;
    
    // buffer to scan is 512 
    BYTE buffer [BUFFER_SIZE]; 
    
    char filename[FILENAME];
    
    //creating a counter for outfile file names to increment
    int index = -1;

    // open memory card read 512 bytes into buffer
    while (fread(&buffer, sizeof(BYTE), BUFFER_SIZE, file) != 0)
    {
        // Check first 4 bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if true
            jpeg = true;
            
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            index++;
            sprintf(filename, "%03i.jpg", index);
            outfile = fopen(filename, "w");
            fwrite(&buffer, sizeof(BYTE), BUFFER_SIZE, outfile);
        }
        // if not found jpeg
        else
        {
            if (jpeg == true)
            {
                // continue to write in file
                fwrite(&buffer, sizeof(BYTE), BUFFER_SIZE, outfile);
            }
        }
    }

    // Close file
    fclose(file);
    
    fclose(outfile);
    
    return 0;
    
}