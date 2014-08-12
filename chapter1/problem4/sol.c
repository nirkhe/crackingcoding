/*
 * Chinmay Nirkhe
 * Solution Ch1P4
 */

#include <stdio.h>
#include <stdlib.h>
#include "memcheck.h"

char* space(char input[], int length)
{
    int i; /* Iterator */
    int j; /* Iterator */
    int space_count = 0; /* Count of number of spaces */
    int true_length;
    
    for(i = 0; i < length; ++i)
    {
        if(input[i] == ' ')
        {
            space_count++;
        }
    }
    
    true_length = length + space_count * 2;
    j = true_length - 1;
    
    /* Now we read the input in reverse and move characters accordingly */
    
    for(i = length - 1; i >= 0; --i)
    {
        if(input[i] == ' ')
        {
            input[j--] = '0';
            input[j--] = '2';
            input[j--] = '%';
        }
        else
        {
            input[j--] = input[i];
        }
    }
    
    return input;
}

int main(void)
{
    char s[] = "Mr John Smith    ";
    printf("%s\n", space(s,13));
    
    print_memory_leaks();
    
    return 0;
}
