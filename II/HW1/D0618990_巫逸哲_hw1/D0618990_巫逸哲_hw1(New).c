#include<stdio.h>

int Account,Option,MoneyIn,money[3],i;

void OptionFac(){
	Option:
	printf("1. 領錢\n2. 存錢\n");
	printf("Option:");
	scanf("%d",&Option);
	
	if(Option == 1){
		printf("金額:");
		scanf("%d",&MoneyIn);
		(MoneyIn > money[Account])? (printf("餘額不足!!!\n")) : (money[Account] = money[Account] - MoneyIn);
	}else if(Option == 2){
		printf("金額:");
		scanf("%d",&MoneyIn);
		money[Account] = money[Account] + MoneyIn;
	}else{
		printf("Wrong Option!!!\n");
		goto Option;
	}
	printf("帳戶_0%d 餘額:%6d\n",Account,money[Account]);
	return;
}

int main(){
	for(i=0;i<3;i++){
		money[i]=0;
	}
	do{
		printf("======== IECS BANK ========\n");
		printf("輸入帳戶編號：");
		scanf("%d",&Account);
		if(Account == 1 || Account == 2 || Account == 3){
			OptionFac();
		}else{
			printf("Wrong Number!!!\n");
		} 
		printf("\n");
	}while(Account!=0);
	printf("Bye Bye\n");
	return 0;
}
