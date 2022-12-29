 if (i == 0 && j == 0)
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 4.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 4.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 4.0);

                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }

            if (i == 0 && j < (width - 1))
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);

                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }

            if (i == 0 && j == (width - 1))
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) / 4.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 4.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 4.0);

                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }

            if (j == 0 && i < height - 1)
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);

                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }

            if (i == (height - 1) && j == 0)
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 4.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 4.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 4.0);

                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }

            if (i == (height - 1) && j < width - 1)
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 6.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 6.0);

                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }

            if (i == (height - 1) && j == (width - 1))
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed) / 4.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen) / 4.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue) / 4.0);

                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }

            if (i < (height - 1) && j == (width - 1))
            {
                totalRed = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 6.0);
                totalGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 6.0);
                totalBlue = round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 6.0);


                image[i][j].rgbtRed = totalRed;
                image[i][j].rgbtGreen = totalGreen;
                image[i][j].rgbtBlue = totalBlue;
            }
            
            
            
            // newest fix took away corner green smile
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += copy[i][j + 1].rgbtRed;
                green += copy[i][j + 1].rgbtGreen;
                blue += copy[i][j + 1].rgbtBlue;
                count++;
            }
            
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += copy[i - 1][j + 1].rgbtRed;
                green += copy[i - 1][j + 1].rgbtGreen;
                blue += copy[i - 1][j + 1].rgbtBlue;
                count++;
            }
            
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += copy[i + 1][j].rgbtRed;
                green += copy[i + 1][j].rgbtGreen;
                blue += copy[i + 1][j].rgbtBlue;
                count++;
            }
            
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += copy[i + 1][j - 1].rgbtRed;
                green += copy[i + 1][j - 1].rgbtGreen;
                blue += copy[i + 1][j - 1].rgbtBlue;
                count++;
            }
            
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += copy[i + 1][j + 1].rgbtRed;
                green += copy[i + 1][j + 1].rgbtGreen;
                blue += copy[i + 1][j + 1].rgbtBlue;
                count++;
            }
            
            
            
            if ((i >= 1 && i < height && j == 0) || (i >= 1 && i < height && j == width))
                    {
                        red += copy[i + row][j + col].rgbtRed;
                        green += copy[i + row][j + col].rgbtGreen;
                        blue += copy[i + row][j + col].rgbtBlue;
                        count++;
                    }
                    
                    if ((i == 0 && j >= 1 && j < width) || (i == height && j >= 1 && j < width))
                    {
                        red += copy[i + row][j + col].rgbtRed;
                        green += copy[i + row][j + col].rgbtGreen;
                        blue += copy[i + row][j + col].rgbtBlue;
                        count++;
                    }
                    
                    
                    
                     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }

    }
