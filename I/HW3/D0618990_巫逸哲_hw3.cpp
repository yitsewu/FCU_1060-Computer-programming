#include<stdio.h>

int main(){
	int moneyin,num;
	
	printf("�Ч�J���B:");
	scanf("%d",&moneyin);
	
	printf("\n\n�z��J�����B��%d��\n\n",moneyin);
	printf("�ӫ~�N��  ����\n  (1)      10 \n  (2)      50 \n  (3)      100\n  (4)      87 \n");
	
	printf("\n�п�J�ӫ~�N��:");
	scanf("%d",&num);
	
	switch(num){
		case 1:
			if(moneyin >= 10){
				printf("\n�ӫ~ 1 �ʶR�����A�h�� %d ��",moneyin-10);
			}
			else{
				printf("\n�ӫ~ 1 �ʶR����");
			}
			break;
		case 2:
			if(moneyin >= 50){
				printf("\n�ӫ~ 2 �ʶR�����A�h�� %d ��",moneyin-50);
			}
			else{
				printf("\n�ӫ~ 2 �ʶR����");
			}
			break;
		case 3:
			if(moneyin >= 100){
				printf("\n�ӫ~ 3 �ʶR�����A�h�� %d ��",moneyin-100);
			}
			else{
				printf("\n�ӫ~ 3 �ʶR����");
			}
			break;
		case 4:
			if(moneyin >= 10){
				printf("\n�ӫ~ 4 �ʶR�����A�h�� %d ��",moneyin-87);
			}
			else{
				printf("\n�ӫ~ 4 �ʶR����");
			}
			break;
		default:
			printf("\n�A��J�F���s�b�����~");
	}
	return 0;
} 
