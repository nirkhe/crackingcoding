/*
 * Chinmay Nirkhe
 * Solution 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int permutation(char *s, char *t)
{
    int i; /* Iteratior */
    int* letters;
    
    if (strlen(s) != strlen(t))
    {
        return 0;
    }
    
    letters = (int *)malloc(128 * sizeof(int));
    
    for(i = 0; i < strlen(s); ++i)
    {
        letters[(int)s[i]]++;
    }
       
    for(i = 0; i < strlen(t); ++i)
    {
        if (--letters[(int)t[i]] < 0)
        {
            free(letters);
            return 0;
        }
    }
    
    free(letters);
    return 1;
}

int main(void)
{
    char s[] = "abcdefghijklmnopqrstuvwxyzz";
    char t[] = "bcdefghijklmnopqrstuvwxyzab";
    
    printf("%d\n",permutation(s,t));
    
    return 0;
}