#include<stdio.h>


int main(){
	int ID,Option,Myin,moneyA = 0,moneyB = 0,moneyC = 0;
	
	while(1){
		printf("======== IECS BANK ========\n");
		printf("��J�b��s���G");
		scanf("%d",&ID);
		switch(ID){
			case 0:{
				printf("Bye Bye\n");
				return 0;
			}
			case 1:{
				Option1:
				printf("1. ���\n2. �s��\n");
				printf("Option:");
				scanf("%d",&Option);
				
				switch(Option){
					case 1:
						printf("���B:");
						scanf("%d",&Myin);
						(Myin > moneyA)? (printf("�l�B����!!!\n")) : (moneyA = moneyA - Myin);
						printf("�b��_01 �l�B:%6d\n",moneyA);
						break;
					case 2:
						printf("���B:");
						scanf("%d",&Myin);
						moneyA = moneyA + Myin;
						printf("�b��_01 �l�B:%6d\n",moneyA);
						break;
					default: 
						printf("Wrong Option!!!\n");
						goto Option1;
						break;
				}
				break;
			}
			case 2:{
				Option2:
				printf("1. ���\n2. �s��\n");
				printf("Option:");
				scanf("%d",&Option);
				
				switch(Option){
					case 1:
						printf("���B:");
						scanf("%d",&Myin);
						(Myin > moneyB)? (printf("�l�B����!!!\n")) : (moneyB = moneyB - Myin);
						printf("�b��_02 �l�B:%6d\n",moneyB);
						break;
					case 2:
						printf("���B:");
						scanf("%d",&Myin);
						moneyB = moneyB + Myin;
						printf("�b��_02 �l�B:%6d\n",moneyB);
						break;
					default: 
						printf("Wrong Option!!!\n");
						goto Option2;
						break;
				}
				break;
			}
			case 3:{
				Option3:
				printf("1. ���\n2. �s��\n");
				printf("Option:");
				scanf("%d",&Option);
				
				switch(Option){
					case 1:
						printf("���B:");
						scanf("%d",&Myin);
						(Myin > moneyC)? (printf("�l�B����!!!\n")) : (moneyC = moneyC - Myin);
						printf("�b��_03 �l�B:%6d\n",moneyC);
						break;
					case 2:
						printf("���B:");
						scanf("%d",&Myin);
						moneyC = moneyC + Myin;
						printf("�b��_03 �l�B:%6d\n",moneyC);
						break;
					default:
						printf("Wrong Option!!!\n");
						goto Option3;
						break;
				}
				break;
			}
			default:{
				printf("�L���b���A�Э��s��J\n");
				break;
			}
		}
	printf("\n");
	}
	return 0;
}
