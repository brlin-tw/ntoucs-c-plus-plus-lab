#include <cstdio>
#include <malloc.h>


int main()
{

    int *ptr;
    int i;

    
    ptr = new int[100];
    for (i=0; i<100; i++)
        ptr[i] = i;
    delete[] ptr;
    /*free(ptr);*/
    
    return 0;
}
