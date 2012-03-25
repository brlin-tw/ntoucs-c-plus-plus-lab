#include <cstdio>
#include <malloc.h>

#include "memory_leak.h"

void main()
{
    set_initial_leak_test();
    int *ptr;
    int i;

    
    ptr = new int[100];
    for (i=0; i<100; i++)
        ptr[i] = i;
    //delete[] ptr;
    /*free(ptr);*/
    
    return ;
}