#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float r, b, g;
    int media;
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            r = image[i][h].rgbtRed;
            b = image[i][h].rgbtBlue;
            g = image[i][h].rgbtGreen;

            media = (int) roundf((r + b + g) / 3);


            image[i][h].rgbtRed = media;
            image[i][h].rgbtBlue = media;
            image[i][h].rgbtGreen = media;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int r, b, g;

    for (int i = 0; i < height; i++)
    {
        int tam = width - 1;
        for (int h = 0; h < (width / 2); h++)
        {
            r = image[i][h].rgbtRed;
            b = image[i][h].rgbtBlue;
            g = image[i][h].rgbtGreen;

            image[i][h].rgbtRed = image[i][tam].rgbtRed;
            image[i][h].rgbtBlue = image[i][tam].rgbtBlue;
            image[i][h].rgbtGreen = image[i][tam].rgbtGreen;

            image[i][tam].rgbtRed = r;
            image[i][tam].rgbtBlue = b;
            image[i][tam].rgbtGreen = g;

            tam--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float r, b, g, count;
    RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            image2[i][h] = image[i][h];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            r = b = g = count = 0;

            r = image2[i][h].rgbtRed;
            b = image2[i][h].rgbtBlue;
            g = image2[i][h].rgbtGreen;
            count++;

            if (i != 0 && i != height - 1)
            {
                if (h != 0)
                {
                    r += image2[i][h - 1].rgbtRed;
                    b += image2[i][h - 1].rgbtBlue; // D
                    g += image2[i][h - 1].rgbtGreen;
                    count++;

                    r += image2[i - 1][h - 1].rgbtRed;
                    b += image2[i - 1][h - 1].rgbtBlue; // A
                    g += image2[i - 1][h - 1].rgbtGreen;
                    count++;

                    r += image2[i + 1][h - 1].rgbtRed;
                    b += image2[i + 1][h - 1].rgbtBlue; // G
                    g += image2[i + 1][h - 1].rgbtGreen;
                    count++;
                }
                if (h != width - 1)
                {
                    r += image2[i][h + 1].rgbtRed;
                    b += image2[i][h + 1].rgbtBlue; // F
                    g += image2[i][h + 1].rgbtGreen;
                    count++;

                    r += image2[i - 1][h + 1].rgbtRed;
                    b += image2[i - 1][h + 1].rgbtBlue; // C
                    g += image2[i - 1][h + 1].rgbtGreen;
                    count++;

                    r += image2[i + 1][h + 1].rgbtRed;
                    b += image2[i + 1][h + 1].rgbtBlue; // I
                    g += image2[i + 1][h + 1].rgbtGreen;
                    count++;
                }

                // todos computam B e H
                r += image2[i - 1][h].rgbtRed;
                b += image2[i - 1][h].rgbtBlue; // B
                g += image2[i - 1][h].rgbtGreen;
                count++;

                r += image2[i + 1][h].rgbtRed;
                b += image2[i + 1][h].rgbtBlue; // H
                g += image2[i + 1][h].rgbtGreen;
                count++;
            }
            else
            {
                if (i != 0)
                {
                    if (h != 0)
                    {
                        r += image2[i][h - 1].rgbtRed;
                        b += image2[i][h - 1].rgbtBlue; // D
                        g += image2[i][h - 1].rgbtGreen;
                        count++;

                        r += image2[i - 1][h - 1].rgbtRed;
                        b += image2[i - 1][h - 1].rgbtBlue; // A
                        g += image2[i - 1][h - 1].rgbtGreen;
                        count++;
                    }

                    if (h != width - 1)
                    {
                        r += image2[i - 1][h + 1].rgbtRed;
                        b += image2[i - 1][h + 1].rgbtBlue; // C
                        g += image2[i - 1][h + 1].rgbtGreen;
                        count++;

                        r += image2[i][h + 1].rgbtRed;
                        b += image2[i][h + 1].rgbtBlue; // F
                        g += image2[i][h + 1].rgbtGreen;
                        count++;
                    }

                    r += image2[i - 1][h].rgbtRed;
                    b += image2[i - 1][h].rgbtBlue; // B
                    g += image2[i - 1][h].rgbtGreen;
                    count++;
                }

                else
                {
                    if (h != 0)
                    {
                        r += image2[i][h - 1].rgbtRed;
                        b += image2[i][h - 1].rgbtBlue; // D
                        g += image2[i][h - 1].rgbtGreen;
                        count++;

                        r += image2[i + 1][h - 1].rgbtRed;
                        b += image2[i + 1][h - 1].rgbtBlue; // G
                        g += image2[i + 1][h - 1].rgbtGreen;
                        count++;
                    }

                    if (h != width - 1)
                    {
                        r += image2[i + 1][h + 1].rgbtRed;
                        b += image2[i + 1][h + 1].rgbtBlue; // I
                        g += image2[i + 1][h + 1].rgbtGreen;
                        count++;
                        r += image2[i][h + 1].rgbtRed;
                        b += image2[i][h + 1].rgbtBlue; // F
                        g += image2[i][h + 1].rgbtGreen;
                        count++;
                    }

                    r += image2[i + 1][h].rgbtRed;
                    b += image2[i + 1][h].rgbtBlue; // H
                    g += image2[i + 1][h].rgbtGreen;
                    count++;
                }
            }

            image[i][h].rgbtRed = (int) roundf(r / count);
            image[i][h].rgbtBlue = (int) roundf(b / count);
            image[i][h].rgbtGreen = (int) roundf(g / count);
        }
    }
    image = image2;
    return;
}

// Detect edges ERROR
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    float r_gx, b_gx, g_gx, r_gy, b_gy, g_gy, r, b, g;
    int r1, b1, g1;
    RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            image2[i][h] = image[i][h];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            r_gx = b_gx = g_gx = r_gy = b_gy = g_gy = 0;

            if(i != 0 && i != height - 1)
            {
                if (h != 0)
                {
                    r_gx += (- 1) * image2[i - 1][h - 1].rgbtRed;
                    b_gx += (- 1) * image2[i - 1][h - 1].rgbtBlue; // A
                    g_gx += (- 1) * image2[i - 1][h - 1].rgbtGreen;

                    r_gy += (- 1) * image2[i - 1][h - 1].rgbtRed;
                    b_gy += (- 1) * image2[i - 1][h - 1].rgbtBlue; // A
                    g_gy += (- 1) * image2[i - 1][h - 1].rgbtGreen;

                    r_gx += (- 1) * image2[i + 1][h - 1].rgbtRed;
                    b_gx += (- 1) * image2[i + 1][h - 1].rgbtBlue; // G
                    g_gx += (- 1) * image2[i + 1][h - 1].rgbtGreen;

                    r_gy += 1 * image2[i + 1][h - 1].rgbtRed;
                    b_gy += 1 * image2[i + 1][h - 1].rgbtBlue; // G
                    g_gy += 1 * image2[i + 1][h - 1].rgbtGreen;

                    r_gx += (- 2) * image2[i][h - 1].rgbtRed;
                    b_gx += (- 2) * image2[i][h - 1].rgbtBlue; // D
                    g_gx += (- 2) * image2[i][h - 1].rgbtGreen;
                }
                if (h != width - 1)
                {
                    r_gx += 1 * image2[i - 1][h + 1].rgbtRed;
                    b_gx += 1 * image2[i - 1][h + 1].rgbtBlue; // C
                    g_gx += 1 * image2[i - 1][h + 1].rgbtGreen;

                    r_gy += (- 1) * image2[i - 1][h + 1].rgbtRed;
                    b_gy += (- 1) * image2[i - 1][h + 1].rgbtBlue; // C
                    g_gy += (- 1) * image2[i - 1][h + 1].rgbtGreen;

                    r_gx += 1 * image2[i + 1][h + 1].rgbtRed;
                    b_gx += 1 * image2[i + 1][h + 1].rgbtBlue; // I
                    g_gx += 1 * image2[i + 1][h + 1].rgbtGreen;

                    r_gy += 1 * image2[i + 1][h + 1].rgbtRed;
                    b_gy += 1 * image2[i + 1][h + 1].rgbtBlue; // I
                    g_gy += 1 * image2[i + 1][h + 1].rgbtGreen;

                    r_gx += 2 * image2[i][h + 1].rgbtRed;
                    b_gx += 2 * image2[i][h + 1].rgbtBlue; // F
                    g_gx += 2 * image2[i][h + 1].rgbtGreen;
                }
                r_gy += (- 2) * image2[i - 1][h].rgbtRed;
                b_gy += (- 2) * image2[i - 1][h].rgbtBlue; // B
                g_gy += (- 2) * image2[i - 1][h].rgbtGreen;

                r_gy += 2 * image2[i + 1][h].rgbtRed;
                b_gy += 2 * image2[i + 1][h].rgbtBlue; // H
                g_gy += 2 * image2[i + 1][h].rgbtGreen;
            }

            else
            {
                if (i != 0)
                {
                    if (h != 0)
                    {
                        r_gx += (- 2) * image2[i][h - 1].rgbtRed;
                        b_gx += (- 2) * image2[i][h - 1].rgbtBlue; // D
                        g_gx += (- 2) * image2[i][h - 1].rgbtGreen;

                        r_gx += (- 1) * image2[i - 1][h - 1].rgbtRed;
                        b_gx += (- 1) * image2[i - 1][h - 1].rgbtBlue; // A
                        g_gx += (- 1) * image2[i - 1][h - 1].rgbtGreen;

                        r_gy += (- 1) * image2[i - 1][h - 1].rgbtRed;
                        b_gy += (- 1) * image2[i - 1][h - 1].rgbtBlue; // A
                        g_gy += (- 1) * image2[i - 1][h - 1].rgbtGreen;
                    }
                    if (h != width - 1)
                    {
                        r_gx += 1 * image2[i - 1][h + 1].rgbtRed;
                        b_gx += 1 * image2[i - 1][h + 1].rgbtBlue; // C
                        g_gx += 1 * image2[i - 1][h + 1].rgbtGreen;

                        r_gy += (- 1) * image2[i - 1][h + 1].rgbtRed;
                        b_gy += (- 1) * image2[i - 1][h + 1].rgbtBlue; // C
                        g_gy += (- 1) * image2[i - 1][h + 1].rgbtGreen;

                        r_gx += 2 * image2[i][h + 1].rgbtRed;
                        b_gx += 2 * image2[i][h + 1].rgbtBlue; // F
                        g_gx += 2 * image2[i][h + 1].rgbtGreen;
                    }

                    r_gy += (- 2) * image2[i - 1][h].rgbtRed;
                    b_gy += (- 2) * image2[i - 1][h].rgbtBlue; // B
                    g_gy += (- 2) * image2[i - 1][h].rgbtGreen;
                }

                if (i != height - 1)
                {
                    if (h != 0)
                    {
                        r_gx += (- 1) * image2[i + 1][h - 1].rgbtRed;
                        b_gx += (- 1) * image2[i + 1][h - 1].rgbtBlue; // G
                        g_gx += (- 1) * image2[i + 1][h - 1].rgbtGreen;

                        r_gy += 1 * image2[i + 1][h - 1].rgbtRed;
                        b_gy += 1 * image2[i + 1][h - 1].rgbtBlue; // G
                        g_gy += 1 * image2[i + 1][h - 1].rgbtGreen;

                        r_gx += (- 2) * image2[i][h - 1].rgbtRed;
                        b_gx += (- 2) * image2[i][h - 1].rgbtBlue; // D
                        g_gx += (- 2) * image2[i][h - 1].rgbtGreen;
                    }
                    if (h != width - 1)
                    {
                       r_gx += 1 * image2[i + 1][h + 1].rgbtRed;
                       b_gx += 1 * image2[i + 1][h + 1].rgbtBlue; // I
                       g_gx += 1 * image2[i + 1][h + 1].rgbtGreen;

                       r_gy += 1 * image2[i + 1][h + 1].rgbtRed;
                       b_gy += 1 * image2[i + 1][h + 1].rgbtBlue; // I
                       g_gy += 1 * image2[i + 1][h + 1].rgbtGreen;

                       r_gx += 2 * image2[i][h + 1].rgbtRed;
                       b_gx += 2 * image2[i][h + 1].rgbtBlue; // F
                       g_gx += 2 * image2[i][h + 1].rgbtGreen;
                    }

                    r_gy += 2 * image2[i + 1][h].rgbtRed;
                    b_gy += 2 * image2[i + 1][h].rgbtBlue; // H
                    g_gy += 2 * image2[i + 1][h].rgbtGreen;
                }
            }



            r = sqrt(pow(r_gx, 2) + pow(r_gy, 2));
            b = sqrt(pow(b_gx, 2) + pow(b_gy, 2));
            g = sqrt(pow(g_gx, 2) + pow(g_gy, 2));

            r1 = (int) round(r);
            b1 = (int) round(b);
            g1 = (int) round(g);

            if (r1 > 255)
            {
                r1 = 255;
            }
            else
            {
                if (r1 < 0)
                {
                    r1 = 0;
                }
            }

            if (b1 > 255)
            {
                b1 = 255;
            }
            else
            {
                if (b1 < 0)
                {
                    b1 = 0;
                }
            }

            if (g1 > 255)
            {
                g1 = 255;
            }
            else
            {
                if (g1 < 0)
                {
                    g1 = 0;
                }
            }

            image[i][h].rgbtRed = r1;
            image[i][h].rgbtBlue = b1;
            image[i][h].rgbtGreen = g1;
        }
    }
    image = image2;
    return;
}
