/*Name	:	Jasmine Chieng
  Date	: 	18/10/2021
  Reference: Curtin University Malaysia. 2018."Lecture 5: Input and Output".
*/

#include <stdio.h>
#include <stdlib.h>
#include "writeToFile.h"
#include "LinkedList.h"
#define ROW 20
#define COL 48

int* readFile(char* fileName)
{
	FILE* ptrf;/*declaring file pointer*/
	int x, y;
	int array[ROW][COL];
	int* ptrArray;
	ptrArray = &array[0][0];
	
	ptrf = fopen(fileName, "r");/*opens file*/	
	if(ptrf == NULL)           
	{
		printf("Error: could not open 'file.txt'\n");
	}
	else if(ferror(ptrf))           
	{
		perror("Error reading from 'file.txt'\n");
	}
	else
	{
		/*Read from the file*/
		while(!feof (ptrf))
    	{
    		for(x=0; x<ROW; x++)
    		{
    			for(y=0; y<COL; y++)
    			{
					fscanf(ptrf, "%d", &array[x][y]);
				}
			}
		}
	}
	fclose(ptrf);
	return ptrArray;
}/*end of readFile()*/

void writeFile(char *fileName, LinkedList *list, int length)
{	
	int *result;
	FILE* wrtPtr;/*declaring file pointer*/
	wrtPtr = fopen(fileName, "w");
	
	result = (int *)removeStart(list);
	fwrite(result, sizeof(int), 1, wrtPtr);
	fclose(wrtPtr);
	free(wrtPtr);
	
}
