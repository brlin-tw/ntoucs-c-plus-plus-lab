// cl  testMemLeakage1.cpp memory_leak.cpp

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
    int i;
    for (i=0; i<10; i++)
        foo();
}