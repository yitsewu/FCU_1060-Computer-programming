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
	FILE *outptr = NULL; 
	NODE *head = NULL, *current, *temp_node;
	int i = 0, num = 0, temp = 0, randnum = 0, input = 0;
	char ch, op;
	
	srand(time(NULL));

	/* 亂數產生數字 */
	for(i = 0; i < 10; i++){
		randnum = rand() % 100;
		
		/* 新增節點 */
		if(head == NULL){
			head = GenerateNode(randnum);
			printf("%d ", head->num);
			current = head;
		}
		else{
			current -> next = GenerateNode(randnum);
			printf("%d ", current->next->num);
			current -> next -> prev = current;
			current = current -> next;		
		}
	}
	
	current->next = head;
	head->prev = current;
	
	
	current = head;
	
	printf("\n1 : to head, 2 : to tail\n");
	printf("\n previous|  current|     next|\n       %2d|       %2d|       %2d|", current->prev->num, current->num, current->next->num);
	
	while(1){
		scanf("%d", &input);
		
		if(input == 0){
			break;
		} else if(input == 1){
			current = current->next;
			printf("\n previous|  current|     next|\n       %2d|       %2d|       %2d|", current->prev->num, current->num, current->next->num);
		} else if(input == 2){
			current = current->prev;
			printf("\n previous|  current|     next|\n       %2d|       %2d|       %2d|", current->prev->num, current->num, current->next->num);
		}
		
		if(current == NULL){
			break;
		}
	}
	
	/* close file pointer*/
	fclose(outptr);
 
	return 0;
}



