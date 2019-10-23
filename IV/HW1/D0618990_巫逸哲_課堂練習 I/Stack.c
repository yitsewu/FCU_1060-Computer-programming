#include <stdio.h>
#include <stdlib.h>

/* �ŧi���c */
typedef struct Node{
	int num;
	struct Node *next;
	struct node *prev;
}NODE;

NODE *top = NULL;  //���V���|���ݪ�����

/*�N���w����Ʀs�J���|*/
void push(int num){
	NODE *new_node;  //�s�[�J�`�I������
	/*�t�m�s�`�I���O����*/
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->num = num;  //�N�ǤJ���ȳ]���`�I�����e 
	
	/*------------------*/
	
	new_node->next = top;   //�N�s�`�I���V���|���I�� 
	top = new_node;  //�s�`�I�������|������ 
} 

/*�q���|���X���*/
int pop(){
	NODE *ptr;  //���V���|���ݪ�����
	int temp;
	if(top == NULL){
		printf("���|����\n");
	}else{
		ptr=top;  //���V���|������
		temp=ptr->num; //���X���|���
		top=top->next; //�N���|���ݪ����Ы��V�U�@�Ӹ`�I 
		free(ptr); //�N�`�I�e�Ϊ��O��������
		return temp; 
	}
}
 
int main() {
	int value;
	int i;
	printf("�Ш̧ǿ�J5�����:\n");
	for(i=0;i<5;i++){
		scanf("%d",&value);
		push(value);
	}
	printf("====================\n");
	while(top!=NULL){
		printf("���|�u�X�����Ǭ�:%d\n",pop()); 
	}
	pop();
	return 0;
}
