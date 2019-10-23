#include <stdio.h>
#include <stdlib.h>

/* 宣告結構 */
typedef struct Node{
	int num;
	struct Node *next;
	struct node *prev;
}NODE;

NODE *top = NULL;  //指向堆疊頂端的指標

/*將指定的資料存入堆疊*/
void push(int num){
	NODE *new_node;  //新加入節點的指標
	/*配置新節點的記憶體*/
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->num = num;  //將傳入的值設為節點的內容 
	
	/*------------------*/
	
	new_node->next = top;   //將新節點指向堆疊的點端 
	top = new_node;  //新節點成為堆疊的頂端 
} 

/*從堆疊取出資料*/
int pop(){
	NODE *ptr;  //指向堆疊頂端的指標
	int temp;
	if(top == NULL){
		printf("堆疊為空\n");
	}else{
		ptr=top;  //指向堆疊的頂端
		temp=ptr->num; //取出堆疊資料
		top=top->next; //將堆疊頂端的指標指向下一個節點 
		free(ptr); //將節點占用的記憶體釋放
		return temp; 
	}
}
 
int main() {
	int value;
	int i;
	printf("請依序輸入5筆資料:\n");
	for(i=0;i<5;i++){
		scanf("%d",&value);
		push(value);
	}
	printf("====================\n");
	while(top!=NULL){
		printf("堆疊彈出的順序為:%d\n",pop()); 
	}
	pop();
	return 0;
}
