#include<stdio.h>

int main(){
	int A,B,C;
	float A1,A2,A3;
	
	printf("請輸入數值A:");
	scanf("%d",&A);
	printf("請輸入數值B:");
	scanf("%d",&B);
	printf("請輸入數值C:");
	scanf("%d",&C);
	
	if(2*C != 0 && (C-B) != 0 && (B+2)*C-2 != 0){
	A1 = (float)(5*A+3*B)/(2*C);
	A2 = (float)(A+3*(B-C))/(C-B);
	A3 = (float)(3*B+5*A)/((B+2)*C-2);
	printf("一式解:%.2f \n二式解:%.2f \n三式解:%.2f \n",A1,A2,A3);
	}
	
	else{
	printf("分母為0，無法運算");
	}
	
	return 0;
}
