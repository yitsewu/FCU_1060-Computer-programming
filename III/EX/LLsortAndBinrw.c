#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node* next;
}node;

/*使用雙重指標作為引數, 不需要回傳值(回傳0值)*/ 
int sortll_dptr(node** handle){
	node *prev, *current, *tmp, *lptr = NULL;
	char swapped = 1;
	
	if(*handle != NULL){
		while(swapped){											//排序是否結束? (一輪中無節點交換) 
			swapped = 0;
			current = *handle;
			prev = NULL;
			while(current->next != lptr){						//這一輪是否結束? (current->next == 結束標記) 
				if(current->num < current->next->num){			//要交換的狀況 
					if(prev == NULL) *handle = current->next;	//交換對象是head節點 
					else prev->next = current->next;			//交換對象不是head節點 
					tmp = current->next;
					current->next = tmp->next;
					tmp->next = current;
					prev = tmp;
					swapped = 1;
				}
				else{											//不交換的狀況, 單純移動prev, current 
					prev = current;
					current = current->next;
				}
			}
			lptr = current;
		}
	}
	
	return 0;
}

/*使用指標作為引數, 需要回傳新的head指標*/
node* sortll_ptr(node* handle){								//改參數, 回傳型態 
	node *prev, *current, *tmp, *lptr = NULL;
	char swapped = 1;
	
	if(handle != NULL){										//改判斷的對象 
		while(swapped){
			swapped = 0;
			current = handle;
			prev = NULL;
			while(current->next != lptr){
				if(current->num < current->next->num){
					if(prev == NULL) handle = current->next;//改對象 
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
	
	return handle;											//設定回傳 
}

int main(){
	node *head = NULL, *current;
	int i;
	
	/*初始化, 建立一個新串列*/
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
	
	/*將串列寫入二進位檔*/
	FILE* fptr = fopen("node.bin", "wb");
	current = head;
	while(current){
		fwrite(current, sizeof(node), 1, fptr);
		current = current->next;
	}
	fclose(fptr);
	
	/*從二進位檔讀回並建立新串列*/ 
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
	
	/*印出head2串列*/
	current = head2;
	while(current){
		printf("%d\n", current->num);
		current = current->next;
	}
	
	//使用雙重指標作為引數 
	//sortll_dptr(&head2);
	//使用指標作為引數, 要重新設定新的head(接收回傳的head) 
	head2 = sortll_ptr(head2);
	printf("---------------------------------\n");
	
	/*再印一次*/
	current = head2;
	while(current){
		printf("%d\n", current->num);
		current = current->next;
	}
	
	return 0;
}
