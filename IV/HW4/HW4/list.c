#include "list.h"

/* LIST CREATE */
NODE *createlist(){
	return NULL;
}

/* QUEUE PUSH */
void pushnode(list *dest, char word){
	NODE *current = *dest;
	NODE *new_node;
	
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->word = word;
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

/* QUEUE POP*/
void qpopnode(list *dest){
	NODE *current = *dest;
	NODE *del;
	
	del = *dest;
	*dest = current->next;
	free(del);
}

/* ¦L¥X¦ê¦C */
void printlist(int RN_flag, int Counter, list dest){
	NODE *current = dest;
	
	if(Counter == 0) return;
	
	(RN_flag)? printf("r") : printf("n");

	printf("%d",Counter);
	
	if(RN_flag){
		printf("%c", current->word);
	} else {
		while(!RN_flag){
			if(current->next == NULL){
				break;
			} else {
				printf("%c", current->word);
				current = current->next;
			}
		}
	}

}


/* TEST TOOL*/
int isempty(list dest){
	if(dest == NULL){
		return 1;
		printf("is_empty\n");
	} else {
		return 0;
		printf("Something inside\n");
	}
}

void printalllist(list print){
	NODE *current = print;
	
	while(1){
		if(current == NULL){
			break;
		}
		printf("%c", current->word);
		current = current->next;
	}
} 
