#include<stdio.h>

int Account,Option,MoneyIn,money[3],i;

void OptionFac(){
	Option:
	printf("1. ���\n2. �s��\n");
	printf("Option:");
	scanf("%d",&Option);
	
	if(Option == 1){
		printf("���B:");
		scanf("%d",&MoneyIn);
		(MoneyIn > money[Account])? (printf("�l�B����!!!\n")) : (money[Account] = money[Account] - MoneyIn);
	}else if(Option == 2){
		printf("���B:");
		scanf("%d",&MoneyIn);
		money[Account] = money[Account] + MoneyIn;
	}else{
		printf("Wrong Option!!!\n");
		goto Option;
	}
	printf("�b��_0%d �l�B:%6d\n",Account,money[Account]);
	return;
}

int main(){
	for(i=0;i<3;i++){
		money[i]=0;
	}
	do{
		printf("======== IECS BANK ========\n");
		printf("��J�b��s���G");
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
