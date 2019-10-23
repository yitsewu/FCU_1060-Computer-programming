#include "list.h"

/* �ХߪŸ`�I */
NODE *createlist(){
	return NULL;
}

/* �s�W�@�ӫ��w���Ʀr�`�I */
void newnode(list *dest, int num){
	NODE *current = *dest;
	NODE *new_node;
	
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->number = num;
	new_node->next = NULL;
	
	while(1){
		if(*dest == NULL){
			*dest = new_node;
			break;
		} else {
			if(current->next == NULL){
				current->next = new_node;
				break;
			} else {
				current = current->next;
			}
		}
	}
}

/* �R����C���Ҧ����w���Ʀr�`�I */ 
void delnode(list dest, int num){
	NODE *del, *current = dest;
	
	while(1){  
		if(current->number == num){
			dest = current->next;
			break;
		} else{
			del = current->next;
			current->next = current->next->next;
			free(del);
		}
		current = current->next;
	}
}

/* ��@��src��C���dest��C�᭱ */
void append(list dest, list src){
	NODE *current = dest;
	
	while(1){
		if(current->next == NULL){
			current->next = src;
			break;
		}
		current = current->next;
	}
	
}

/* �L�X��C */
void printlist(list print){
	NODE *current = print;
	
	while(1){
		if(current->next == NULL){
			printf("%2d", current->number);
			break;
		}
		printf("%2d, ", current->number);
		current = current->next;
	}
} 
