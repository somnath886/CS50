// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    float n = atof(argv[1]);
    int p = round(n * 10);


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

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

    float Height = bi.biHeight * n;
    float Width = bi.biWidth * n;
    int oldHeight = bi.biHeight;
    int oldWidth = bi.biWidth;
    int newHeight = round(Height);
    int newWidth = round(Width);
    double h = (double) oldHeight / (double) newHeight;
    double w = (double) oldWidth / (double) newWidth;


    int inpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpadding = (4 - (newWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biHeight = newHeight;
    bi.biWidth = newWidth;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * newWidth) + outpadding) * abs(newHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);



    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    RGBTRIPLE scanned[oldWidth * sizeof(RGBTRIPLE)];
    RGBTRIPLE triple[newWidth * sizeof(RGBTRIPLE)];

    // iterate over infile's scanlines

    for (int i = 0, biHeight = abs(oldHeight); i < biHeight; i++)
    {
        int x = i * h;

        for (int j = 0; j < oldWidth; j++)
        {
            int y = j * w;
            fread(scanned, sizeof(RGBTRIPLE), oldWidth, inptr);
            for (int k = 0; k < 1; k++)
            {
                triple[y + k] = scanned[y + k];
            }

        }

        fseek(inptr, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (((sizeof(RGBTRIPLE) * oldWidth) + inpadding) * x), SEEK_SET);
        for (int j = 0; j < 1; j++)
        {
            fwrite(triple, sizeof(RGBTRIPLE), newWidth, outptr);
            for (int k = 0; k < outpadding; k++)
            {
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
