#include<stdio.h>
#include<string.h>

typedef struct Account{
	char name[10];
	char account[20];
	char password[20];	
	double money;
}ACCOUNT;

int main(){
	int i, add = 0, modchose = -1;
	
	ACCOUNT memberOfBank[500];
	memset(memberOfBank, 0, sizeof(memberOfBank));
	
	ACCOUNT tempmember;
	
	printf("---歡迎使用本系統---\n");
	
	while(modchose!=0){
		modchose = -1;
		
		printf("\n功\能選擇:\n(1) 建立帳戶\n(2) 提款\n(3) 存款\n(4) 修改密碼\n(5) 查詢餘額\n(6) 轉帳\n(0) 結束系統\n--------------------\n請輸入:");
		
//		fflush(stdin);
		 
		scanf("%d",&modchose);
		
		if(modchose > 6 || modchose < 0){
			printf("無此功\能，請重新選擇\n");
		} else if(modchose == 1){
			for(; add < 500; add++){
				printf("\n---建立您的帳號---\n姓名:");
				scanf("%s",memberOfBank[add].name);
				printf("\n帳號:");
				scanf("%s",memberOfBank[add].account);
				printf("\n密碼:");
				scanf("%s",memberOfBank[add].password);
				printf("\n---建立成功\---\n");
				
				memberOfBank[add].money = 10000;
				
				break;
			}
		} else if(modchose <= 6 && modchose >= 1){
			printf("\n需要進行登入\n\n請輸入帳號:");
			scanf("%s",tempmember.account);
			printf("\n請輸入密碼:");
			scanf("%s",tempmember.password);
			
			for(i = 0; i <= add; i++){
				if(strcmp(tempmember.account, memberOfBank[i].account) == 0){
					if(strcmp(tempmember.password, memberOfBank[i].password) == 0){
						printf("\n\n登入成功\\n\n");
						printf("歡迎 ");
						printf("%s",memberOfBank[i].name);
						printf(" 回來，帳戶餘額: %.lf", memberOfBank[i].money);				
						if(modchose == 2){
							printf("\n請輸入提款金額:");
							scanf("%lf",&tempmember.money);
							memberOfBank[i].money = memberOfBank[i].money - tempmember.money;
							printf("\n\n提款成功\\n\n");
							break;
						} else if(modchose == 3){
							printf("\n請輸入存款金額:");
							scanf("%lf",&tempmember.money);
							memberOfBank[i].money+=tempmember.money;
							printf("\n\n存款成功\\n\n");
							break;
						} else if(modchose == 4){
							printf("\n請輸入新密碼:");
							scanf("%s",&memberOfBank[i].password);
							printf("\n\n修改成功\\n\n");
							break;
						} else if(modchose == 5){
							printf("\n\n您的餘額為 %5.lf\n",memberOfBank[i].money);
							break;
						} else if(modchose == 6) {
							printf("\n需要進行登入\n\n請輸入帳號:");
							scanf("%s",tempmember.account);
							
							printf("\n請輸入轉帳金額:");
							scanf("%lf",&tempmember2.money);
							memberOfBank[i].money += tempmember.money;
						} 
					} else {
						printf("\n\n登入失敗\n\n"); 
					} 
				} else {
					printf("\n\n登入失敗\n\n"); 
				}
			}
		}
	}
	
	printf("---\n系統結束，歡迎您下次使用---\n");
	
	return 0;
} 
