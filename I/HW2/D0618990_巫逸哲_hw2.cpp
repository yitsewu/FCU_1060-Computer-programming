#include<stdio.h>

int main(){
	int A,B,C;
	float A1,A2,A3;
	
	printf("�п�J�ƭ�A:");
	scanf("%d",&A);
	printf("�п�J�ƭ�B:");
	scanf("%d",&B);
	printf("�п�J�ƭ�C:");
	scanf("%d",&C);
	
	if(2*C != 0 && (C-B) != 0 && (B+2)*C-2 != 0){
	A1 = (float)(5*A+3*B)/(2*C);
	A2 = (float)(A+3*(B-C))/(C-B);
	A3 = (float)(3*B+5*A)/((B+2)*C-2);
	printf("�@����:%.2f \n�G����:%.2f \n�T����:%.2f \n",A1,A2,A3);
	}
	
	else{
	printf("������0�A�L�k�B��");
	}
	
	return 0;
}
