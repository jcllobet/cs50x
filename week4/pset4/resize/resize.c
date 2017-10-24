/**
 * resize.c
 *
 * CS50x Pset4 - Jan Carbonell
 *
 * Resizes bmp by a scale of n from initial file to a new one
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[]) {

    // ensure proper usage
    if (argc != 4) {
        fprintf(stderr, "Usage: ./whodunit fileToRead fileToWrite scale\n");
        return 1;
    }

    // remember filenames and scale size
    char *infile = argv[2];
    char *outfile = argv[3];

    int scale_size =atoi(argv[1]);

    // reasonable scale
    if (scale_size < 1 || scale_size > 100) {
        fprintf(stderr, "The scale (s) must be: 1 < s < 100\n");
        return 1;
    }


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL) {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL) {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0) {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // create outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPFILEHEADER final_bf = bf;
    BITMAPINFOHEADER final_bi = bi;

    //rescale the new dimensions of the final file
    final_bi.biWidth *= scale_size;
    final_bi.biHeight *= scale_size;

    // determine padding for scanlines
    int initial_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int final_padding = (4 - (final_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //final biSizeImage and bfSize (biSize Image + 54bytes of header)
    final_bi.biSizeImage = abs(final_bi.biHeight) * (final_bi.biWidth * sizeof(RGBTRIPLE)+ final_padding);
    final_bf.bfSize = (final_bi.biSizeImage + 54);

    // write outfile's BITMAPFILEHEADER
    fwrite(&final_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&final_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++) {

        // repeat each line until its = scalesize
        for (int j = 0; j < scale_size; j++) {

            //set pointer to initial line
            // *i since we need to skip to the begginning of each line
            fseek (inptr, 54 + (bi.biWidth * 3 + initial_padding)*i, SEEK_SET);

            //iterate over pixels in scanline
            for (int s = 0; s < bi.biWidth; s++) {

                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                //iterate each pixel n times
                for (int p = 0; p < scale_size; p++) {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // then add it back (to demonstrate how)
            for (int k = 0; k < final_padding; k++) {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
