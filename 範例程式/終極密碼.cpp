#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int n,Real,InputNum,Min = 0,Max = 101,Times,Guestcout=0;
	float InputNumCheak;
	
	do{
		
		printf("  歡迎遊玩終極密碼  \n");
		
		srand(time(NULL));
		Real = (rand()%100)+1;
		
		printf("\n    密碼生成成功\  \n\n");
		printf("密碼為 1~100 的整數\n\n");
		
		//printf("密碼為%d\n\n",Real); 
	
		while(InputNum!=Real){
			
			printf("數字介於 %d ~ %d 之間\n\n請輸入一個數:",Min,Max);
			scanf("%f",&InputNumCheak);
			InputNum = (int)InputNumCheak;
			
				if(InputNumCheak - InputNum != 0){
					printf("\n請輸入整數\n\n");
				}
				else if(InputNum <= 0){
					printf("\n數字介於 %d ~ %d 之間\n",Min,Max);
				}
				else{
			
					if(InputNum >= Max || InputNum <= Min){
						printf("\n未在範圍內\n請重新輸入\n\n");
					}
					else{
						if(InputNum!= Real){
							printf("\n猜錯了，再猜一次\n");
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
		printf("\n太棒了，你猜中了\n");
		printf("----------------------\n\n");
		printf("\n你總共猜了%d次\n",Guestcout);
		printf("\n\n");
		printf("----------------------\n\n");
	}while(1);
	return 0;
}
