#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

//using RGBTRIPLE structure
#include "bmp.h"

//making a green pixel
//RGBTRIPLE triple;
//triple.rgbtBlue = 0x00;
//triple.rgbtGreen = 0xff;
//triple.rgbtRed = 0x00;

//how to have a trully blue pixel?
//first set rgbtGreen and rgbtRed to 0x00;


int main(int argc, char *argv[])
{
    //accepts only 2 command line arguments
    if (argc != 3){
        fprintf(stderr, "Usage: ./whodunit FileToRead FileToWrite \n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    // fread (data, size, numner, inptr)
    //data: pointer to a struct that will contain the bytes you are reading
    //size: size of each element to read
    //number: elements to read
    //inptr: FILE * to read from
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    // the length of each scanline must be a multiple of 4
    // the padding is just 0000.
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //Removing RED NOISE (from full to quite towards 0)
            if (triple.rgbtRed == 255)
            {
                triple.rgbtRed = 255;
                triple.rgbtGreen = 255;
                triple.rgbtBlue = 255;
            }

            else if (triple.rgbtBlue == 255)
            {
                triple.rgbtRed = 0;
                triple.rgbtGreen = 0;
            }

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        // fseek (intptr, offset, from);
        //offset: number of bytes to move cursor
        //from: SEEK_CUR (current position in file)
        //      SEEK_SET (beginning of file)
        //      SEEK_END (end of file)
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;

}
