#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int number;
	struct node *next;
}NODE;

typedef NODE *list;

NODE *createlist();
void newnode(list *dest, int num);	//�s�W�@�ӫ��w���Ʀr�`�I 
void delnode(list dest, int num);	//�R����C���Ҧ����w���Ʀr�`�I 
void append(list dest, list src);	//��@��src��C���dest��C�᭱
void printlist(list print);

#endif
