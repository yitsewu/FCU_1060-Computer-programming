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
	
	printf("---�w��ϥΥ��t��---\n");
	
	while(modchose!=0){
		modchose = -1;
		
		printf("\n�\\����:\n(1) �إ߱b��\n(2) ����\n(3) �s��\n(4) �ק�K�X\n(5) �d�߾l�B\n(6) ��b\n(0) �����t��\n--------------------\n�п�J:");
		
//		fflush(stdin);
		 
		scanf("%d",&modchose);
		
		if(modchose > 6 || modchose < 0){
			printf("�L���\\��A�Э��s���\n");
		} else if(modchose == 1){
			for(; add < 500; add++){
				printf("\n---�إ߱z���b��---\n�m�W:");
				scanf("%s",memberOfBank[add].name);
				printf("\n�b��:");
				scanf("%s",memberOfBank[add].account);
				printf("\n�K�X:");
				scanf("%s",memberOfBank[add].password);
				printf("\n---�إߦ��\\---\n");
				
				memberOfBank[add].money = 10000;
				
				break;
			}
		} else if(modchose <= 6 && modchose >= 1){
			printf("\n�ݭn�i��n�J\n\n�п�J�b��:");
			scanf("%s",tempmember.account);
			printf("\n�п�J�K�X:");
			scanf("%s",tempmember.password);
			
			for(i = 0; i <= add; i++){
				if(strcmp(tempmember.account, memberOfBank[i].account) == 0){
					if(strcmp(tempmember.password, memberOfBank[i].password) == 0){
						printf("\n\n�n�J���\\\n\n");
						printf("�w�� ");
						printf("%s",memberOfBank[i].name);
						printf(" �^�ӡA�b��l�B: %.lf", memberOfBank[i].money);				
						if(modchose == 2){
							printf("\n�п�J���ڪ��B:");
							scanf("%lf",&tempmember.money);
							memberOfBank[i].money = memberOfBank[i].money - tempmember.money;
							printf("\n\n���ڦ��\\\n\n");
							break;
						} else if(modchose == 3){
							printf("\n�п�J�s�ڪ��B:");
							scanf("%lf",&tempmember.money);
							memberOfBank[i].money+=tempmember.money;
							printf("\n\n�s�ڦ��\\\n\n");
							break;
						} else if(modchose == 4){
							printf("\n�п�J�s�K�X:");
							scanf("%s",&memberOfBank[i].password);
							printf("\n\n�ק令�\\\n\n");
							break;
						} else if(modchose == 5){
							printf("\n\n�z���l�B�� %5.lf\n",memberOfBank[i].money);
							break;
						} else if(modchose == 6) {
							printf("\n�ݭn�i��n�J\n\n�п�J�b��:");
							scanf("%s",tempmember.account);
							
							printf("\n�п�J��b���B:");
							scanf("%lf",&tempmember2.money);
							memberOfBank[i].money += tempmember.money;
						} 
					} else {
						printf("\n\n�n�J����\n\n"); 
					} 
				} else {
					printf("\n\n�n�J����\n\n"); 
				}
			}
		}
	}
	
	printf("---\n�t�ε����A�w��z�U���ϥ�---\n");
	
	return 0;
} 
