#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct
{
    int entry;/*to store new values entered*/
    int finalEntry;/*to store the final sum*/
}Result;

void interface(char* fileName);
void printList(void *data);
void freeData(void *data);
void printArr(char **arr, int row, int col, int input);

#endif
