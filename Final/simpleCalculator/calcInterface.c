#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"calcInterface.h"
#include"terminal.h"
#include"macros.h"
#include"LinkedList.h"
#include"writeToFile.h"

/*FUNCTION PROTOTYPING*/
void printList(void *data);/*function for printing the data in the list*/
void freeData(void *data);/*function for freeing the data in the list*/
void printArr(char **arr, int row, int col, int input);/*function for printing the visual interface*/


void interface(char* fileName)
{	
	LinkedList *list = NULL;
    int llLength = 2;
    Result *res = NULL;
    char **arr = NULL;
    char temp = ' ';
    char new=' ';
    char *input2 = NULL;
    int newInt = 0;
    char c1[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '0', '='};
    char c2[12] = {'+', '0', '=', '7', '8', '9', '4', '5', '6', '1', '2', '3'};
    int i=7, j=0, x, row=12, col=9;
    int rPos, cPos=0;
    char key;
    int quit = FALSE;
    int deleteNow = FALSE;
    int count=0, added=0;
    int output = 0;

    list = createLinkedList();
    input2 = (char *)malloc(7 * sizeof(char));

    arr = (char **)malloc(row * sizeof(char *));
    for(i=0; i<row; i++)    
    {
	arr[i]= (char *)malloc(col * sizeof(char));
    }	
    	
    input2[0] = '0';
    for(i=1; i<7; i++)    
    {
    	input2[i] = ' ';
    }
    	
    for(i=0; i<row; i++)    
    {
	for(j=0; j<col; j++)    
    	{	
    	    arr[i][j] = ' ' ;
    	}
    }
 	   
    for(i=0; i<col; i++)    
    {
    	arr[0][i] = '-';
    	arr[2][i] = '-';
    }
    for(i=1; i<2; i++)    
    {
    	arr[i][0] = '|';
    	arr[i][col-1] = '|';
    }
    	
    arr[1][7]='0';

    /*calculator keypad*/
    srand(time(NULL));
    if(rand()%2==0)
    {
	for(i=4; i<row; i++)    
    	{
	   for(j=0; j<3; j++)    
	   {
		if(i%2==0)/*means its an even numbered row*/
    		{
    		    arr[i][j] = c1[x];
    		    x++;
    		}
	   }
    	}
    }
    else
    {
    	for(i=4; i<row; i++)    
    	{
	   for(j=0; j<3; j++)    
	   {
    		if(i%2==0)/*means its an even numbered row*/
    		{
		    arr[i][j] = c2[x];
		    x++;
    		}
	   }
    	}
    }
    	
    if(arr[4][0]=='+')
    {
	arr[5][cPos]='^';
	rPos=5;
    }
    else
    {
 	arr[11][cPos]='^';
 	rPos=11;
    }
    	
    system("clear");
    added = atoi(input2);
    printArr(arr, row, col, added);
    	
    disableBuffer();
    scanf("%c", &key);
    
    while(key != 'q')
    {   	
    	if(key== 's')
    	{
	    if(rPos==11)
	    {
		arr[rPos][cPos] = '^';
    		/*the user remains in current position
    		 and does not go beyond keypad limit*/
	    }
	    else
	    {
    		arr[rPos][cPos] = ' ';
    		rPos=rPos+2;
    		arr[rPos][cPos] = '^';/*move down*/
    	    }
    	}
    	else if(key == 'd')
    	{
	    if(cPos==2)
	    {
		arr[rPos][cPos] = '^';
	    }
	    else
    	    {
    		arr[rPos][cPos] = ' ';
    		cPos++;
    		arr[rPos][cPos] = '^';/*move right*/
    	    }
    	}
    	else if(key== 'a')
    	{
    	    if(cPos==0)
    	    {
    		arr[rPos][cPos] = '^';
    	    }
    	    else
    	    {
    		arr[rPos][cPos] = ' ';
    		cPos--;
    		arr[rPos][cPos] = '^';/*move left*/
    	    }
    	}
    	else if(key== 'w')
    	{
    	    if(rPos==5)
    	    {
    		arr[rPos][cPos] = '^';
    	    }
	    else
    	    {
    		arr[rPos][cPos] = ' ';
    		rPos=rPos-2;
    		arr[rPos][cPos] = '^';/*move up*/
    	    }
    	}
    	else if(key == 'e')
    	{
    	    /*meaning that the user has selected '='*/
    	    if(arr[rPos-1][cPos]=='=')
    	    {
    		/*writeFile(fileName, list, llLength);*//*write to a file*/
    		free(input2);
    		quit = TRUE;/*to exit the while loop*/
    	    }
    	    /*when an array selected is number because it is not equal to '=' or '+'*/
    	    else if(arr[rPos-1][cPos]!='=' && arr[rPos-1][cPos]!='+')
    	    {
    		if(count == 0)/*when the uer has not selected anything yet*/
    		{
		    new = arr[rPos-1][cPos];/*contains the selected number in char format*/
    		    arr[1][7] = new;/*to display the selected */
    		    newInt = atoi(&new);/*convert*/
    		    sprintf(input2, "%d", newInt);/*convert the integer format to string format*/
    		    count++;/*new digit has been entered*/
    		}
    		else if(count>0 && count<8)
		{
    		    input2[count] = arr[rPos-1][cPos];/*add new digit(char data type) into the string*/
    		    j=0;
		    for (i = 7; i >= 7-count; i--) /*to store all the digits*/
    		    {
   			arr[1][i] = input2[j];
    			j++;
    		    }
		  if(count==1)/*for when there is only 2 digits*/
		  {
			arr[1][7] = input2[1];
    			arr[1][6] = input2[0];
		  }
		  else
		  {
    			j = 7;
    			for (i = 7-count; i <=7-count+1; i++) /*to store the digits in the correct order*/
    			{
   			    temp = arr[1][i];
   			    arr[1][i] = arr[1][j];
   			    arr[1][j] = temp;
   			    j--;
    			}
    		    }
    		    count++;
    		}   			
    	    }
    	    else if(arr[rPos-1][cPos]=='+')
    	    {
    	    if(count==0)
    	    {
    	    	printArr(arr, row, col, added);
    	    }
    	    else
    	    {
    	    	/*to remove the last value (which is the last sum)*/
    		if(deleteNow!=FALSE)
    		{
    		    removeLast(list);
    		    llLength++;
    		}
    		
    		res = (Result *)malloc(sizeof(Result));
    		output = atoi(input2);
    		res->entry = output;
    		insertStart(list, res);
    		added = added + output;/*sum of all values*/
    		
		/*add and update the sum*/
		res->finalEntry = added;
    		insertLast(list, res);
    		deleteNow = TRUE;/*to enter the if statement to remove the last value in the list*/
    		count = 0;/*to reset the display to 0*/
    	/*reset calculator display*/	
		for(i=1; i<7; i++)    
   		{
    		    arr[1][i] = ' ';
    		}
    		
		arr[1][7] = '0';
	   }
	   }
	
    	}
    	

	system("clear");
    	printArr(arr, row, col, added);
    	/*printLinkedList(list,&printList);*/
    	if(quit == FALSE)
    	{
    	    disableBuffer();
    	    scanf("%c", &key);
    	}
    	else
    	{
    	    key = 'q';
    	}
    }
    	
    	for(i=0; i<row; i++)    
    	{
    	    free(arr[i]);
    	}
    	free(arr);
   	freeLinkedList(list, &freeData);
}

void printList(void *data)
{
    printf("list: %d, %d\n", ((Result *)data)->entry, ((Result *)data)->finalEntry);
}

void freeData(void *data)
{
    free(data);
}

void printArr(char **arr, int row, int col, int input)
{
    int i=0, j;

    for(i=0; i<row; i++)    
    {
    	for(j=0; j<col; j++)    
    	{
    	    if(i<=3)
    	    {
    		printf("%c", arr[i][j]);/*to print calculator display*/
    	    }
    	    else
    	    {
    		printf("%c ", arr[i][j]);/*to print keypad interface*/
    	    }
    	}
    	printf("\n");
    }
    
    printf("\nCurrent Total: %d\n", input);/*to print the current total*/
}

