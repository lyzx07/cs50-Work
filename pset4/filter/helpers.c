#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through the 2d array
    float average;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            //average each pixel to produce equal values of each color to turn gray
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;

    //iterate through 2d array
    int sepiaR, sepiaG, sepiaB;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            //use they formula for sepia provided to find the new color values
            sepiaR = round((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue));
            sepiaG = round((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue));
            sepiaB = round((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue));


            //check to see if the value excedes 255
            image[i][j].rgbtRed = (sepiaR > 255) ? 255 : sepiaR;
            image[i][j].rgbtGreen = (sepiaG > 255) ? 255 : sepiaG;
            image[i][j].rgbtBlue = (sepiaB > 255) ? 255 : sepiaB;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through 2d array
    RGBTRIPLE temp;
    float mid = round(width / 2.0);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            //use reflect formula to reflect the pixels
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through 2d array
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float count = 0.0;
            int red = 0;
            int green = 0;
            int blue = 0;

            //iterate through  + one row and + 1 column in either direction
            for (int row = -1; row < 2; row++)
            {
                for (int col = -1; col < 2; col++)
                {
                    //skip counting pixel that doesn't exist
                    if (i + row < 0 || i + row > height - 1 || j + col < 0 || j + col > width - 1)
                    {
                        continue;
                    }


                    red += image[i + row][j + col].rgbtRed;
                    green += image[i + row][j + col].rgbtGreen;
                    blue += image[i + row][j + col].rgbtBlue;
                    count++;
                }
            }
            //place new values for pixel in copy of 2d array
            copy[i][j].rgbtRed = round(red / count);
            copy[i][j].rgbtGreen = round(green / count);
            copy[i][j].rgbtBlue = round(blue / count);


        }

    }
    //iterate through 2d array to replace original values with the copied value to create blur effect
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;

}
