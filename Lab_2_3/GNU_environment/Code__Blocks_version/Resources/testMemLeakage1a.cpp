// cl /MLd /Zi testMemLeakage.cpp memory_leak.cpp
// /Zi to include debug information (source level debugging)
// /MLd use libcd.lib (crtdbg)

#include "memory_leak.h"
#include <malloc.h>
#include <stdio.h>

struct File
{
    char *name;
    char *data;
};

void foo()
{
    struct File *filePtr;

    filePtr = (struct File *) malloc(sizeof(struct File));
    filePtr->name = (char *) malloc(200*sizeof(char));
    filePtr->data = (char *) malloc(5000*sizeof(char));
    printf("%p %p %p\n", filePtr, filePtr->name, filePtr->data);
    // do something
    free(filePtr);
}

void main()
{
    set_initial_leak_test();

    int i;
    for (i=0; i<10; i++)
        foo();
}