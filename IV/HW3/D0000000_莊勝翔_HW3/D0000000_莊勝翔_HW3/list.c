#include "list.h"

node* createlist(){
	return NULL; 
}

void newnode(list* dest, int num){		//�s�W�@�ӫ��w���Ʀr�`�I 
	node* curr = *dest;
	node* tmp;
	
	tmp = (node*)malloc(sizeof(node));
	tmp -> number = num;
	tmp -> next = NULL;
	
	while(1){
		if(*dest == NULL){
			*dest = tmp;
			break;
		}else if(curr -> next == NULL){
			curr -> next = tmp;
			break;
		}
		curr = curr -> next;
	}
	
}

void delnode(list* dest, int num){		//�R����C���Ҧ����w���Ʀr�`�I 
	node* curr = *dest;
	node* tmp;
	
	while(1){
		if(curr -> number == num){
			*dest = curr -> next;
			break;
		}else {
			tmp = curr -> next;
			curr -> next = curr -> next -> next;
			free(tmp);
		}
		curr = curr -> next;
	}
}

void append(list* dest, list* src){		//��@��src��C���dest��C�᭱
	node* curr = *dest;
	
	while(1){
		if(curr -> next != NULL){
			curr = curr -> next;
		}else{
			curr -> next = *src;
			break;
		}
	}
}

void printlist(list print){				//�L�Xlist 
	node *curr = print;
	
	for(;;){
		if(curr->next != NULL){
			printf("%d, ", curr->number);
			curr = curr->next;
		}else{
			printf("%d", curr->number);
			break;
		}
	}
}
