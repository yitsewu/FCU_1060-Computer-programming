#include<stdio.h>
#include<string.h>

#define Square 3
#define Matrix1 0
#define Matrix2 1
#define AnsMatrixofMatrix1PlusMatrix2 2
#define AnsTwoTimesMatrix1PlusMatrix2 3
#define AnsEightTimesMatrix2 4
#define AnsMatrix1CrossMatrix2 5

int matrix[2+4][Square][Square];//宣告 matrix為全域變數

void printfMatrix(int i){
	int j, k;
	for(j = 0; j < Square; j++){
		for(k = 0; k < Square; k++){
			printf("%5d ",matrix[i][j][k]);
		}
		printf("\n");
	}
	printf("\n");
}

void scanfMatrix(void){
	int i, j, k;
	for(i = 0; i < 2; i++){
		printf("Input Matrix %d : ",i+1);
		for(j = 0; j < Square; j++){
			for(k = 0; k < Square; k++){
				scanf("%d",&matrix[i][j][k]);
			}
		}
		printfMatrix(i);
	}
	printf("==================================\n");
}

void Matrix1PlusMatrix2(void){
	int i, j, k;
	printf("Matrix1 Plus Matrix2\n");
	for(j = 0; j < Square; j++){
		for(k = 0; k < Square; k++){
			for(i = 0; i < Square - 1; i++){
				matrix[AnsMatrixofMatrix1PlusMatrix2][j][k] += matrix[i][j][k];
			}
		}
	}
	printfMatrix(AnsMatrixofMatrix1PlusMatrix2);
}

void TwoTimesMatrix1PlusMatrix2(void){
	int i, j, k;
	printf("Two Times Matrix1 Plus Matrix2\n");
	for(j = 0; j < Square; j++){
		for(k = 0; k < Square; k++){
			matrix[AnsTwoTimesMatrix1PlusMatrix2][j][k] = 2*(matrix[Matrix1][j][k]) + matrix[Matrix2][j][k];
			
		}
	}
	printfMatrix(AnsTwoTimesMatrix1PlusMatrix2);
}

void EightTimesMatrix2(void){
	int j, k;
	printf("Eight Times Matrix2\n");
	for(j = 0; j < Square; j++){
		for(k = 0; k < Square; k++){
			matrix[AnsEightTimesMatrix2][j][k] = 8*(matrix[Matrix2][j][k]);
		}
	}
	printfMatrix(AnsEightTimesMatrix2);
}

void Matrix1CrossMatrix2(void){
	int i, j, k;
	printf("Matrix1 Cross Matrix2\n");
	
	for(i = 0; i < Square ; i++){
		for(j = 0; j < Square; j++){
			for(k = 0; k < Square; k++){
				matrix[AnsMatrix1CrossMatrix2][i][j] += matrix[Matrix1][i][k]*matrix[Matrix2][k][j];
			}
		}
	}
	printfMatrix(AnsMatrix1CrossMatrix2);
}

int main(void){
	memset(matrix, 0, sizeof(matrix));
	scanfMatrix();
	Matrix1PlusMatrix2();
	TwoTimesMatrix1PlusMatrix2();
	EightTimesMatrix2();
	Matrix1CrossMatrix2();
	return 0;
} 
