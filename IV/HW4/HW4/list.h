#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char word;
	struct node *next;
}NODE;

typedef NODE *list;

NODE *createlist();										//LIST CREATE

void pushnode(list *dest, char word);					//QUEUE PUSH
void qpopnode(list *dest);								//QUEUE POP

void printlist(int RN_flag, int Counter, list dest);

///* TEST TOOL*/
int isempty(list dest);
void printalllist(list print);

#endif
