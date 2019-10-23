#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char word;
	struct node *next;
}NODE;

NODE *GenerateNode(char word){
	NODE *new_node;
	
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->word = word;
	new_node->next = NULL;
	
	return new_node;
}

int main(){
	FILE *inptr = NULL, *outptr = NULL;
	NODE *head = NULL, *current;
	
	int RCounter = 0, NCounter = 0;
	char word;
	
	/* file pointer */
	inptr = fopen("RLEinput.txt", "r");
	outptr = fopen("output.txt", "w");
	
	if(inptr == NULL) return 0;
	
	/* link list*/
	while(1){
		fscanf(inptr, "%c", &word);
		
		if(head == NULL){
			head = GenerateNode(word);
			current = head;
		} else {
			if(word == current->word && feof(inptr) == 0){
				current->rtimes++;
				curr_flag = 1;
			} else {
				current->next = GenerateNode(word);
				if(curr_flag == 1){
					curr = current->next;
					curr_flag = 0;
				}
				curr->ntimes++;
				current = current->next;
			}
		}
		if(feof(inptr) != 0) break;
	}
	
	/* show & write file */
	PrintAllNode(head);
	WriteFile(head, outptr);
	
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
	
	return 0;
} 
