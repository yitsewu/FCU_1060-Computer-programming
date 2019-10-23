#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node* next;
}NODE;

NODE* GenerateNode(int n){
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> num = n;
	new_node -> next = NULL;
	return new_node;
}

void InsertNode(NODE *target, NODE *newnode){
	newnode -> next = target -> next;
	target -> next = newnode;
}

void DeleteNode(NODE *node, NODE *deletenode){
	node -> next = deletenode -> next;
	free(deletenode);
}

void SearchNode(NODE *node, int num){
	NODE *current;
	current = node;
	
	while(current != NULL){
		if(current -> num == num){
			current -> num = 999;
			break;
		}
		current = current -> next;
	}
	
}

void PrintNode(NODE *node){
	/* �L�X��� Linked List */
	NODE *current;
	current = node;

	while(current != NULL){
		printf("%3d  ", current -> num);
		current = current -> next;
	}
	
	printf("\n");
}

int main(){
	int i = 0;
	
	NODE *head, *current, *insertnode;
	head = GenerateNode(0);
	current = head;
	
	for(i = 1; i < 10; i++){
		current -> next = GenerateNode(i);
		current = current -> next;
	}
	
	printf("��l\t : ");
	PrintNode(head);
	
	/* ���J�@�Ӹ`�I�� Linked List */
	current = head;
	while(current != NULL){
		if(current -> num == 3){
			insertnode = GenerateNode(99);
			InsertNode(current, insertnode);
			break;
		}
		current = current -> next;
	}
	
	printf("�s�W�`�I : ");
	PrintNode(head);
	
	/* �R�� Linked List �@�Ӹ`�I */
	current = head;
	while(current != NULL){
		if(current -> next -> num == 99){
			DeleteNode(current, current -> next);
			break;
		}
		current = current -> next;
	}
	
	printf("�R���`�I : ");
	PrintNode(head);
	
	/* �j�M�ç�� Linked List �@�Ӹ`�I */
	SearchNode(head, 6);
	
	printf("�j�M�`�I : ");
	PrintNode(head);
	
	return 0;
}



