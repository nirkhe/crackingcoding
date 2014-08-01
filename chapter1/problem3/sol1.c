/*
 * Chinmay Nirkhe
 * Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparestring(const void *a, const void *b)
{
    return *(const char *)a - *(const char *)b;
}

int permutation(char *s, char *t)
{
    int i = 0; /* Iterator */
    
    if (strlen(s) != strlen(t))
    {
        return 0;
    }
    
    qsort(s, strlen(s), 1, comparestring);
    qsort(t, strlen(s), 1, comparestring);
    
    for(; i < strlen(s); ++i)
    {
        if(s[i] != t[i])
        {
            return 0;
        }
    }
    
    return 1;
}

int main(void)
{
    char s[] = "abcdefghijklmnopqrstuvwyz";
    char t[] = "bcdefghijklmnopqrstuvwyza";
    
    printf("%d\n",permutation(s,t));

    return 0;
}