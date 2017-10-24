/**
 * recover.c
 *
 * CS50x - Pset 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <cs50.h>


int main(int argc, char *argv[])
{
    //accepts only 2 command line arguments
    if (argc != 2){
        fprintf(stderr, "Usage: ./recover memoryCard \n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    const int BLOCK_SIZE = 512;

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL) {
        fprintf(stderr, "File not found! %s.\n", infile);
        return 2;
    }


    unsigned char buffer[BLOCK_SIZE];

    //pointer to outfile
    FILE* outptr = NULL;

    //make space for jpg file image
    char recover[9];

    // number of files created
    int file_counter = 0;

    while (fread(buffer, 1, 512, inptr)) {


        //if we find the header patter of bytes
        if (buffer[0] == 0xff && buffer [1] == 0xd8 && buffer [2] == 0xff && buffer [3] >= 0xe0 && buffer[3] <= 0xef) {

            if (file_counter > 0){
                fclose(outptr);
            }

            //make a name for i'th image
            sprintf(recover, "%03i.jpg", file_counter);

            //open i'th image file
            outptr = fopen(recover, "w");
            if (outptr == NULL){
                fprintf(stderr, "Could not create %s.\n", infile);
                return 3;
            }

            //increase the counter of image files recovered
            file_counter++;
        }

        //write to image file only if it exists
        if (outptr != NULL){
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }

    }

    // close infile
    fclose(outptr);

    // close outfile
    fclose(inptr);

    // success
    return 0;

}
