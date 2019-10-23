#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node* next;
}node;

/*�ϥ��������Ч@���޼�, ���ݭn�^�ǭ�(�^��0��)*/ 
int sortll_dptr(node** handle){
	node *prev, *current, *tmp, *lptr = NULL;
	char swapped = 1;
	
	if(*handle != NULL){
		while(swapped){											//�ƧǬO�_����? (�@�����L�`�I�洫) 
			swapped = 0;
			current = *handle;
			prev = NULL;
			while(current->next != lptr){						//�o�@���O�_����? (current->next == �����аO) 
				if(current->num < current->next->num){			//�n�洫�����p 
					if(prev == NULL) *handle = current->next;	//�洫��H�Ohead�`�I 
					else prev->next = current->next;			//�洫��H���Ohead�`�I 
					tmp = current->next;
					current->next = tmp->next;
					tmp->next = current;
					prev = tmp;
					swapped = 1;
				}
				else{											//���洫�����p, ��²���prev, current 
					prev = current;
					current = current->next;
				}
			}
			lptr = current;
		}
	}
	
	return 0;
}

/*�ϥΫ��Ч@���޼�, �ݭn�^�Ƿs��head����*/
node* sortll_ptr(node* handle){								//��Ѽ�, �^�ǫ��A 
	node *prev, *current, *tmp, *lptr = NULL;
	char swapped = 1;
	
	if(handle != NULL){										//��P�_����H 
		while(swapped){
			swapped = 0;
			current = handle;
			prev = NULL;
			while(current->next != lptr){
				if(current->num < current->next->num){
					if(prev == NULL) handle = current->next;//���H 
					else prev->next = current->next;
					tmp = current->next;
					current->next = tmp->next;
					tmp->next = current;
					prev = tmp;
					swapped = 1;
				}
				else{
					prev = current;
					current = current->next;
				}
			}
			lptr = current;
		}
	}
	
	return handle;											//�]�w�^�� 
}

int main(){
	node *head = NULL, *current;
	int i;
	
	/*��l��, �إߤ@�ӷs��C*/
	head = (node*)malloc(sizeof(node));
	head->num = 0;
	head->next = NULL;
	current = head;
	for(i = 1; i < 10; i++){
		current->next = (node*)malloc(sizeof(node));
		current = current->next;
		current->num = i;
		current->next = NULL;
	}
	
	/*�N��C�g�J�G�i����*/
	FILE* fptr = fopen("node.bin", "wb");
	current = head;
	while(current){
		fwrite(current, sizeof(node), 1, fptr);
		current = current->next;
	}
	fclose(fptr);
	
	/*�q�G�i����Ū�^�ëإ߷s��C*/ 
	node *head2 = NULL, *tmp;
	fptr = fopen("node.bin", "rb");
	while(!feof(fptr)){
		tmp = (node*)malloc(sizeof(node));
		if( fread(tmp, sizeof(node), 1, fptr) == 0 ){
			free(tmp);
			break;
		}
		tmp->next = NULL;
		if(head2 == NULL) head2 = tmp;
		else current->next = tmp;
		current = tmp;
	}
	fclose(fptr);
	
	/*�L�Xhead2��C*/
	current = head2;
	while(current){
		printf("%d\n", current->num);
		current = current->next;
	}
	
	//�ϥ��������Ч@���޼� 
	//sortll_dptr(&head2);
	//�ϥΫ��Ч@���޼�, �n���s�]�w�s��head(�����^�Ǫ�head) 
	head2 = sortll_ptr(head2);
	printf("---------------------------------\n");
	
	/*�A�L�@��*/
	current = head2;
	while(current){
		printf("%d\n", current->num);
		current = current->next;
	}
	
	return 0;
}
