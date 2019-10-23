#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* �ŧi���c */
typedef struct node{
	int num;
	struct node *next;
}NODE;

/* �s�W�@�`�I */
NODE* GenerateNode(int num){
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> num = num;
	new_node -> next = NULL;
	return new_node;
}

/* �̷Ӹ��X�Ƨ� */
NODE* SortList(NODE* head) {
    NODE* temp;
    NODE* current = head;
    NODE* prev = head;
    NODE* tail = NULL;
    
    while(head != tail) {
        current = head;
        prev = head;
        
        while(current != NULL && current -> next != NULL && current -> next != tail) {
        	
        	/* �ݭn�洫 */
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
            
            /* ���ݥ洫�A���ܤU�@�� */
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
	
	/* �üƲ��ͼƦr */
	for(i = 0; i < 10; i++){
		randnum = rand() % 100;
		
		/* �s�W�`�I */
		if(head == NULL){
			head = GenerateNode(randnum);
			current = head;
		}
		else{
			current -> next = GenerateNode(randnum);
			current = current -> next;			
		}
	}
	
	/* �L�X�|���ƧǼƦr */
	current = head;
	while(current != NULL){
		printf("%d ", current -> num);
		current = current -> next;
	}
	
	/* �I�s�禡�i��Ƨ� */
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



