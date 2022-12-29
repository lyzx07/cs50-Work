#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//make a datatype the size of a byte of data
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check to make sure that is one command line arguement
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //open new pointer to argv[1]
    FILE *file = fopen(argv[1], "r");

    //check to make sure file isnt NULL
    if (!file)
    {
        printf("could not be opened\n");
        return 1;
    }

    //create an array of bytes
    BYTE buffer[512];
    int count = 0;
    char filename[8];
    FILE *image = NULL;

    //go through entire file till the end
    while (fread(buffer, sizeof(BYTE), 512, file))
    {
        //check the first 4 bytes to see if it's the start of a new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if a new jpeg is found after the first, then close the previous jpeg
            if (count > 0)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", count);

            //open new file to write recovered jpeg and increment counter
            image = fopen(filename, "w");
            count++;
        }

        //write recovered jpeg to new file
        if (count > 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, image);

        }

    }
    //close all files still in use
    fclose(file);
    fclose(image);
    return 0;

}











