//
//  problem3.cpp
//  
//
//  Created by Chinmay Nirkhe on 8/12/14.
//
//

#include "problem3.h"

node* partition(node * head, int x)
{
    node* small = NULL;
    node* large = NULL;
    node* itt = head;
    node* small_start;
    node* large_start;
    
    if(itt != NULL)
    {
        while(itt != NULL)
        {
            if(itt->value <= x)
            {
                if(small == NULL) {small = itt; small_start = itt;}
                else {small->next = itt; small = itt;}
            }
            else
            {
                if(large == NULL) {large = itt; large_start = itt;}
                else{large->next = itt; large = itt;}
            }
            itt = itt->next;
        }
        large->next = NULL;
        small->next = large_start;
        head = small_start;
    }
    
    return head;
}

int main(void)
{
    // seed the PRNG
    srand(time(NULL));
    
    node * head = new node;
    head->value = rand() % 100;
    
    node * itt = head;
    
    // initialize the test array to garbage
    for(int i = 0; i < 20; i++)
    {
        node * temp = new node;
        temp->value = rand() % 100;
        itt->next = temp;
        itt = temp;
    }
    itt->next = NULL;
    
    int x = 50;
    
    head = partition(head, x);
    
    printf("Post Partition \n");
    
    itt = head;
    
    while(itt != NULL)
    {
        printf("%d\n", itt->value);
        node * del = itt;
        itt = itt->next;
        delete(itt);
    }
    
    return 0;
}