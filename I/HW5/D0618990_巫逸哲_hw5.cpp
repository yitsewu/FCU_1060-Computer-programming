#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*第一部分*/ 
int main(){
	/*變數設定區*/ 
	int i,j,IntputNum[30],LineChange = 0,SameCheck;
	float IntputNumCheck[30];
	
	/*隨機初始值設定*/ 
	srand(time(NULL));
	
	/*Input*/ 
	printf("請輸入之正整數，數值範圍(1~100)，數量最多不超過30個，若輸入0則結束:\n\n");
	
	i = 0;//( ←迴圈控制歸零)
    j = 0;//( ←迴圈控制歸零)
    
	while(i >= 0 && i < 30){
		scanf("%f",&IntputNumCheck[i]);
		IntputNum[i] = (int)IntputNumCheck[i];
		
		if(IntputNumCheck[i] - IntputNum[i] != 0){
			printf("[Error!](非整數)，請重新輸入:\n");
		} //( ←輸入小數重新輸入控制，i不進位，則輸入值將直接覆蓋錯誤值)
		else if(IntputNum[i] == 0){
			break;
		}//( ←輸入0結束控制)
		else if(IntputNum[i] < 1 || IntputNum[i] > 100){
			
			printf("[Error!](未在1~100內)，系統將自動生成:\n");
			IntputNum[i] = (rand()%100)+1;
			printf("%d\n",IntputNum[i]);
			
			for(SameCheck = 0;SameCheck < i;SameCheck++){
				if(IntputNum[i] == IntputNum[SameCheck]){
					printf("[Error!](與前方數字重複)，系統將自動生成:\n");
					IntputNum[i] = (rand()%100)+1;
					printf("%d",IntputNum[i]);
					printf("\n重新檢測\n");
					SameCheck = -1; //( ←重啟迴圈，之所以使為-1之原因為迴圈結束後會馬上進行++，所以不能為0)
				}
			}//( ←重複值檢測，成立則自動亂數寫入)
			
			printf("未重複，請繼續輸入\n");
			i++;
		}//( ←輸入超出範圍自動亂數寫入)
		else{
			for(SameCheck = 0;SameCheck < i;SameCheck++){
				if(IntputNum[i] == IntputNum[SameCheck]){
					printf("[Error!]錯誤(與前方數字重複)，系統將自動生成:\n");
					IntputNum[i] = (rand()%100)+1;
					printf("%d",IntputNum[i]);
					printf("\n重新檢測\n");
					SameCheck = -1;//( ←重啟迴圈，之所以使為-1之原因為迴圈結束後會馬上進行++，所以不能為0)
				}
			}//( ←重複值檢測，成立則自動亂數寫入)
			printf("未重複，請繼續輸入\n");
			i++;
		}
	}
	
	j = i;//( ←取輸入次數)
	
	if(i < 30){
		printf("輸入數字未達30個，系統將自動生成:\n");
		for (i = j; i < 30; i++) {
        	IntputNum[i] = (rand()%100)+1;
        	printf("%d\n",IntputNum[i]);
        	for(SameCheck = 0;SameCheck < i;SameCheck++){
				if(IntputNum[i] == IntputNum[SameCheck]){
					printf("[Error!]錯誤(與前方數字重複)，系統將自動生成:\n");
					IntputNum[i] = (rand()%100)+1;
					printf("%d",IntputNum[i]);
					printf("\n重新檢測\n");
					SameCheck = -1;//( ←重啟迴圈，之所以使為-1之原因為迴圈結束後會馬上進行++，所以不能為0)
				}
			}//( ←重複值檢測，成立則自動亂數寫入)
			printf("未重複，請繼續輸入\n");
    	}
	}
	
	
	/*Output*/

	i = 0;//( ←控制迴圈歸零)
	
	while(i >= 0 && i < 30){
		//(作業一功能 : 當輸入 0 時結束(不含 0)。結束時印出輸入之所有數字。)
		//( ↑若要將改為0結束輸出，則將上方 i < 30 改為 j - 1中 ↑)
		printf("%5d",IntputNum[i]);
		i++;
		LineChange++;//( ←換行控制迴圈)
		if(LineChange == 10){
			printf("\n");
			LineChange = 0;
		}
	}
	return 0;
}
