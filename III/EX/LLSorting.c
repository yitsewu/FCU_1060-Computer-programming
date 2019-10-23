#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 宣告結構 */
typedef struct node{
	int num;
	struct node *next;
}NODE;

/* 新增一節點 */
NODE* GenerateNode(int num){
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> num = num;
	new_node -> next = NULL;
	return new_node;
}

/* 依照號碼排序 */
NODE* SortList(NODE* head) {
    NODE* temp;
    NODE* current = head;
    NODE* prev = head;
    NODE* tail = NULL;
    
    while(head != tail) {
        current = head;
        prev = head;
        
        while(current != NULL && current -> next != NULL && current -> next != tail) {
        	
        	/* 需要交換 */
            if((current -> num) > (current -> next -> num)) {
                temp = current -> next;
                current -> next = temp -> next;
                temp -> next = current;
                
                if(current == head) {
                    prev = temp;
                    head = temp;
                } 
				else {
                    prev -> next = temp;
                    prev = prev -> next;
                }
            } 
            
            /* 不需交換，移至下一個 */
			else {
                if(current != head) {
                    prev = prev -> next;
                }
                current = current -> next;
            }
        }

        tail = current;
    }
    return head;
}


int main(){
	FILE *outptr = NULL; 
	NODE *head = NULL, *current, *temp_node, *sorting_head = NULL;
	int i = 0, num = 0, temp = 0, randnum = 0;
	char ch, digit[10];
	
	memset(digit, '\0', sizeof(digit));
	srand(time(NULL));
	
	
	/* file pointer */
	outptr = fopen("output.txt", "wb");
	
	/* 亂數產生數字 */
	for(i = 0; i < 10; i++){
		randnum = rand() % 100;
		
		/* 新增節點 */
		if(head == NULL){
			head = GenerateNode(randnum);
			current = head;
		}
		else{
			current -> next = GenerateNode(randnum);
			current = current -> next;			
		}
	}
	
	/* 印出尚未排序數字 */
	current = head;
	while(current != NULL){
		printf("%d ", current -> num);
		current = current -> next;
	}
	
	/* 呼叫函式進行排序 */
	sorting_head = SortList(head);
	
	current = sorting_head;
	while(current != NULL){
		sprintf(digit,"%d",current -> num);
		
		/* write file */
		fwrite(digit, sizeof(int), 1, outptr);
		fwrite("\r\n", sizeof(char), 2, outptr);
		current = current -> next;
	}
	
	
	/* close file pointer*/
	fclose(outptr);
 
	return 0;
}



