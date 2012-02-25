#include <stdio.h>

void readFile(int *dataSize, int data[])
{
     int i;
     FILE *fp;
     char filename[30];

     printf("Input the file name: ");
     gets(filename);

     fp = fopen(filename, "rt");
     fscanf(fp, "%d", dataSize);
     for (i=0; i < *dataSize; i++)
          fscanf(fp, "%d", &data[i]);
     fclose(fp);
}

// output array contents (20 values per row)
void printArray(const int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 20 == 0)  // begin new line every 20 values
            printf("\n");

        printf("%2d", a[i]);

    }
}

