/*
 * Chinmay Nirkhe
 * Solution Ch1P6
 */

#include <stdio.h>

#define SIZE 5

int rotate(int image[][SIZE])
{
    int i, j;
    int temp;
    
    for(i = 0; i <= SIZE / 2; ++i)
    {
        for(j = 0; j < SIZE /2; ++j)
        {
            temp = image[i][j];
            image[i,j] = image[j, SIZE - i - 1];
            image[j, SIZE - i - 1] = image[SIZE - i - 1, SIZE - j - 1];
            image[SIZE - i - 1, SIZE - j - 1] = image[SIZE - j - 1, i];
            image[SIZE - j - 1, i] = temp;
        }
    }
}

int main(void)
{
    int i, j;
    
    int image[SIZE][SIZE];
    
    for(i = 0; i < SIZE; ++i)
    {
        for(j = 0; j < SIZE; ++j)
        {
            image[i][j] = i + j;
        }
    }
    
    rotate(image);
    
    for(i = 0; i < SIZE; ++i)
    {
        for(j = 0; j < SIZE; ++j)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}