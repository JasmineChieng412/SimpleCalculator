#include <stdlib.h>
#include "LinkedList.h"

LinkedList *createLinkedList(void)
{
    LinkedList *theList = NULL;
    theList = (LinkedList*)malloc(sizeof(LinkedList));

    theList->head = NULL;
    theList->count = 0;

    return theList;
}

void insertStart(LinkedList *list, void *entry)
{
    LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    
    newNode->data = entry;
    newNode->next = list->head;
    list->head = newNode;
    
    list->count++;
}

void *removeStart(LinkedList *list)
{
    void *data = NULL;
    LinkedListNode *firstNode = list->head;
	
    if(firstNode != NULL)
    {
	data = firstNode->data;
    	list->head = firstNode->next;
    	free(firstNode);
	list->count--;
    }
    
    return data;
}

void insertLast(LinkedList *list, void *entry)
{
    LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    LinkedListNode *lastNode = NULL;

    newNode->data = entry; /* insert new data */
    newNode->next = NULL;
 
    if(list->head == NULL) 
    {
        list->head = newNode;
    }
    else
    {
 	lastNode = list->head;
    	while(lastNode->next != NULL)
    	{
            lastNode = lastNode->next;
 	}
   	lastNode->next = newNode;
    }

    list->count++;
}

void *removeLast(LinkedList *list)
{
    void *data = NULL;
     LinkedListNode *currNode = list->head;
    LinkedListNode *lastNode = currNode->next;
    
    if(lastNode->next != NULL)
    {
	currNode = currNode->next;
        lastNode = currNode->next;
    }

    data = lastNode->data;
    currNode->next = NULL;

    free(lastNode); 
    list->count--;
    
    return data;
}

void printLinkedList(LinkedList *list, listFunc funcPtr)
{
    LinkedListNode *curr = list->head;
	
    while(curr != NULL)
    {
	(*funcPtr)(curr->data);
	curr = curr->next;
    }
}

void freeLinkedList(LinkedList *list, listFunc funcPtr)
{
    LinkedListNode *currentNode = NULL;

    while(list->head != NULL)
    {
        currentNode = list->head;
        list->head = currentNode->next;
        (*funcPtr)(currentNode->data);
        free(currentNode);
    }

    free(list);
}
