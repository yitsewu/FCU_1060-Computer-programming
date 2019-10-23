#include<stdio.h>


int main(){
	int ID,Option,Myin,moneyA = 0,moneyB = 0,moneyC = 0;
	
	while(1){
		printf("======== IECS BANK ========\n");
		printf("輸入帳戶編號：");
		scanf("%d",&ID);
		switch(ID){
			case 0:{
				printf("Bye Bye\n");
				return 0;
			}
			case 1:{
				Option1:
				printf("1. 領錢\n2. 存錢\n");
				printf("Option:");
				scanf("%d",&Option);
				
				switch(Option){
					case 1:
						printf("金額:");
						scanf("%d",&Myin);
						(Myin > moneyA)? (printf("餘額不足!!!\n")) : (moneyA = moneyA - Myin);
						printf("帳戶_01 餘額:%6d\n",moneyA);
						break;
					case 2:
						printf("金額:");
						scanf("%d",&Myin);
						moneyA = moneyA + Myin;
						printf("帳戶_01 餘額:%6d\n",moneyA);
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
				printf("1. 領錢\n2. 存錢\n");
				printf("Option:");
				scanf("%d",&Option);
				
				switch(Option){
					case 1:
						printf("金額:");
						scanf("%d",&Myin);
						(Myin > moneyB)? (printf("餘額不足!!!\n")) : (moneyB = moneyB - Myin);
						printf("帳戶_02 餘額:%6d\n",moneyB);
						break;
					case 2:
						printf("金額:");
						scanf("%d",&Myin);
						moneyB = moneyB + Myin;
						printf("帳戶_02 餘額:%6d\n",moneyB);
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
				printf("1. 領錢\n2. 存錢\n");
				printf("Option:");
				scanf("%d",&Option);
				
				switch(Option){
					case 1:
						printf("金額:");
						scanf("%d",&Myin);
						(Myin > moneyC)? (printf("餘額不足!!!\n")) : (moneyC = moneyC - Myin);
						printf("帳戶_03 餘額:%6d\n",moneyC);
						break;
					case 2:
						printf("金額:");
						scanf("%d",&Myin);
						moneyC = moneyC + Myin;
						printf("帳戶_03 餘額:%6d\n",moneyC);
						break;
					default:
						printf("Wrong Option!!!\n");
						goto Option3;
						break;
				}
				break;
			}
			default:{
				printf("無此帳號，請重新輸入\n");
				break;
			}
		}
	printf("\n");
	}
	return 0;
}
