#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "LinkedList.h"

int* readFile(char* fileName);
void writeFile(char *fileName, LinkedList *list, int length);

#endif
