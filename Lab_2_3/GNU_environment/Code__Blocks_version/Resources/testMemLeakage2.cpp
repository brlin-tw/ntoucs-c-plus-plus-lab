// cl testMemLeakage2.cpp

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
    filePtr->name = (char *) malloc(2000000*sizeof(char));
    filePtr->data = (char *) malloc(500000000*sizeof(char));
    printf("%p %p %p\n", filePtr, filePtr->name, filePtr->data);
    // do something
    free(filePtr);
}

void main()
{
    int i;
    for (i=0; i<20; i++)
        foo();
}