#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 宣告結構 */
typedef struct node{
	int num;
	struct node *next;
	struct node *prev;
}NODE;

/* 新增一節點 */
NODE* GenerateNode(int num){
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> num = num;
	new_node -> next = NULL;
	return new_node;
}


int main(){
	NODE *head = NULL, *curr, *current, *temp_node;
	int i = 0, num = 0, temp = 0, randnum = 0, flag = 0;
	char ch, op, input[20];
	
	memset(input, 0, sizeof(input));
	srand(time(NULL));
	
	while(1){
		printf(">>");
		scanf("%s",input);
		
		if(strcmp(input,"end") == 0){
			
			break;
			
		} else if(strcmp(input,"push") == 0){
			
			randnum = rand() % 100;
			
			if(head == NULL){
				head = GenerateNode(randnum);
				current = head;
			} else {
				current -> next = GenerateNode(randnum);
				current -> next -> prev = current;
				current = current -> next;		
			}
			
			curr = head;
			
			while(1){
				printf("%2d ", curr -> num);
				curr = curr -> next;
				
				if(curr == NULL){
					printf("\n");
					break;
				}
			}
			
		} else if(strcmp(input,"pop") == 0){
			
			flag = 0;
			
			if(head == NULL){
				printf("The stake is empty.\n");
				flag = 1;
			} else {
				if(current != head){
					current = current -> prev;
					free(current -> next);
					current -> next  = NULL;
				} else {
					free(current -> next);
					head = NULL;
				}
			}
			
			curr = head;
			
			while(1){
				if(head == NULL){
					if(flag == 0){
						printf("The stake is empty.\n");
					}
					break;
				}

				printf("%2d ", curr -> num);
				curr = curr -> next;
				
				if(curr == NULL){
					printf("\n");
					break;
				}
			}
		}
	}
}
