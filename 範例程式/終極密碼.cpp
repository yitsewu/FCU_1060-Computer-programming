#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int n,Real,InputNum,Min = 0,Max = 101,Times,Guestcout=0;
	float InputNumCheak;
	
	do{
		
		printf("  �w��C���׷��K�X  \n");
		
		srand(time(NULL));
		Real = (rand()%100)+1;
		
		printf("\n    �K�X�ͦ����\\  \n\n");
		printf("�K�X�� 1~100 �����\n\n");
		
		//printf("�K�X��%d\n\n",Real); 
	
		while(InputNum!=Real){
			
			printf("�Ʀr���� %d ~ %d ����\n\n�п�J�@�Ӽ�:",Min,Max);
			scanf("%f",&InputNumCheak);
			InputNum = (int)InputNumCheak;
			
				if(InputNumCheak - InputNum != 0){
					printf("\n�п�J���\n\n");
				}
				else if(InputNum <= 0){
					printf("\n�Ʀr���� %d ~ %d ����\n",Min,Max);
				}
				else{
			
					if(InputNum >= Max || InputNum <= Min){
						printf("\n���b�d��\n�Э��s��J\n\n");
					}
					else{
						if(InputNum!= Real){
							printf("\n�q���F�A�A�q�@��\n");
							printf("----------------------\n\n");
						}
						if(InputNum > Real){
							Max = InputNum;
						}
						else if(InputNum < Real){
							Min = InputNum;
						}
					}
				Guestcout++;
				}
		}
		printf("\n�ӴΤF�A�A�q���F\n");
		printf("----------------------\n\n");
		printf("\n�A�`�@�q�F%d��\n",Guestcout);
		printf("\n\n");
		printf("----------------------\n\n");
	}while(1);
	return 0;
}
