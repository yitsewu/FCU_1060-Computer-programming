#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char word;
	int rtimes;
	int ntimes;
	struct node *next;
	struct node *prev;
}NODE;

NODE *GenerateNode(char word){
	NODE *new_node;
	
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->ntimes = -1;
	new_node->rtimes = 1;
	new_node->word = word;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	return new_node;
}

void PrintAllNode(NODE *current){
	while(1){
		if(current->next == NULL) break;
		
		if(current->rtimes != 1){
			printf("r%d",current->rtimes);
		} else if(current->ntimes != -1) {
			printf("n%d",current->ntimes);
		}
		
		printf("%c", current->word);
		current = current->next;
	}
}

void WriteFile(NODE *current, FILE *outptr){
	while(1){
		if(current->next == NULL) break;
		
		if(current->rtimes != 1){
			fprintf(outptr, "r%d",current->rtimes);
		} else if(current->ntimes != -1) {
			fprintf(outptr, "n%d",current->ntimes);
		}
		
		fprintf(outptr,"%c", current->word);
		
		current = current->next;
	}
}

int main(){
	FILE *inptr = NULL, *outptr = NULL;
	NODE *head = NULL, *current, *curr;
	
	int curr_flag = 0;
	char word;
	
	/* file pointer */
	inptr = fopen("input.txt", "r");
	outptr = fopen("output.txt", "w");
	
	if(inptr == NULL) return 0;
	
	/* link list*/
	while(1){
		
		fscanf(inptr, "%c", &word);
		
		if(head == NULL){
			head = GenerateNode(word);
			current = head;
			curr = head;
			curr->ntimes = 0;
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
				current -> next -> prev = current;
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
