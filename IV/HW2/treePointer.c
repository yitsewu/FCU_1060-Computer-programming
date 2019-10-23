#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

/* 宣告結構 */
typedef struct node {
	int data;
	struct node *leftChild;
	struct node *rightChild;
}NODE;


/* 新增一節點 */
NODE *GenerateNode(int num){
	NODE *new_node;
	
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = num;
	new_node->leftChild = NULL;
	new_node->rightChild = NULL;
	
	return new_node;
}

void Preorder(NODE *current){
    if (current != NULL) {
        printf("%d ", current->data);
        Preorder(current->leftChild);
        Preorder(current->rightChild);
    }
}

void Inorder(NODE *current){
    if (current != NULL) {
        Inorder(current->leftChild);
        printf("%d ", current->data);
        Inorder(current->rightChild);
    }
}

void Postorder(NODE *current){
    if (current != NULL) {
        Postorder(current->leftChild);
        Postorder(current->rightChild);
        printf("%d ", current->data);
    }
}

int height(NODE *current){
	int lheight = 0, rheight = 0;
	
    if (current != NULL){
    
        lheight = height(current->leftChild);
        rheight = height(current->rightChild);
 
        if (lheight > rheight){
        	printf("if L||%d ",lheight + 1);
        	printf("if R||%d ",rheight + 1);
        	return (lheight+1);
		} else {
			printf("else L||%d ",lheight + 1);
			printf("else R||%d ",rheight + 1);
			return (rheight+1);
		}
    }
}

void GivenLevel(NODE *current, int level){
    if (current == NULL){
    	return;
	}    
    if (level == 1){
    	printf("%d ", current->data);
	} else if (level > 1){
        GivenLevel(current->leftChild, level-1);
        GivenLevel(current->rightChild, level-1);
    }
}

void LevelOrder(NODE* root){
    int i, h = height(root);
    for (i=1; i<=h; i++){
    	GivenLevel(root, i);
	}
}

int main(){
	NODE *root = NULL, *current;
	int i, j, input[MAX], search[MAX];
	int YN_flag = 0;
	memset(input, 0, sizeof(input));
	memset(search, 0, sizeof(search));
	
	for(i = 0; i < MAX; i++){
		scanf("%d",&input[i]);
		if(input[i] == 0) break;
	}
	
//	for(i = 0; i < MAX; i++){
//		scanf("%d",&search[i]);
//		if(search[i] == 0) break;
//	}
	
	for(i = 0;;i++){
		if(input[i] == 0) break;
		if(root == NULL){
			root = GenerateNode(input[i]);
			current = root;
		} else {
			current = root;
			while(1){
				if(input[i] < current->data){
					if(current->leftChild == NULL){
						current->leftChild = GenerateNode(input[i]);
						break;
					} else {
						current = current->leftChild;
					}
				} else {
					if(current->rightChild == NULL){
						current->rightChild = GenerateNode(input[i]);
						break;
					} else { 
						current = current->rightChild;
					}
				}
			}
		}
	}
	
//	for(i = 0;;i++){
//		if(search[i] == 0){
//			printf("\n");
//			break;
//		}
//		current = root;
//		while(1){
//			if(current == NULL){
//				YN_flag = 0;
//				break;
//			}
//			if(search[i] == current->data){
//				YN_flag = 1;
//				break;
//			} else if(search[i] < current->data){
//				current = current->leftChild;
//			} else if(search[i] > current->data){
//				current = current->rightChild;
//			}
//		}
//		(YN_flag == 1)? printf("Y "):printf("N ");
//	}
//	
//	Preorder(root);
//	printf("\n");
//	
//	Inorder(root);
//	printf("\n");
//	
//	Postorder(root);
//	printf("\n");
	
	LevelOrder(root);
	printf("\n");
	
	return 0;
}
