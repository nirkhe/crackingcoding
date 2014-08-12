/*
 * Chinmay Nirkhe
 * Chapter 1 Problem 8
 * Mon Aug 11 2014
 */

#include <stdio.h>

/*
 * Tests is s1 is a substring of s2
 */
int isSubstring( char *s1, char *s2)
{
    char* i = s1;
    char* j = s2;
    
    while (*j) /* Traverse s2, testing for match */
    {
        if(*i == *j) /* If letters match, then check next letters */
        {
            i++;
            if(!(*i)) {return 1;} /* Entire string matches */
        }
        else /* Did not match, restart matching test */
        {
            i = s1;
        }
        j++;
    }
    return 0; /* Nothing matched */
}

int main(int argc, char ** argv)
{
    char s1[] = "happy";
    char s2[] = "sad is the opposite of happy!";
    
    printf("%d\n", isSubstring(s1, s2));
    
    return 0;
}
