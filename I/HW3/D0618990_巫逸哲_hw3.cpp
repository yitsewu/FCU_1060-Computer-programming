#include<stdio.h>

int main(){
	int moneyin,num;
	
	printf("請投入金額:");
	scanf("%d",&moneyin);
	
	printf("\n\n您投入的金額為%d元\n\n",moneyin);
	printf("商品代號  價錢\n  (1)      10 \n  (2)      50 \n  (3)      100\n  (4)      87 \n");
	
	printf("\n請輸入商品代號:");
	scanf("%d",&num);
	
	switch(num){
		case 1:
			if(moneyin >= 10){
				printf("\n商品 1 購買完成，退幣 %d 元",moneyin-10);
			}
			else{
				printf("\n商品 1 購買失敗");
			}
			break;
		case 2:
			if(moneyin >= 50){
				printf("\n商品 2 購買完成，退幣 %d 元",moneyin-50);
			}
			else{
				printf("\n商品 2 購買失敗");
			}
			break;
		case 3:
			if(moneyin >= 100){
				printf("\n商品 3 購買完成，退幣 %d 元",moneyin-100);
			}
			else{
				printf("\n商品 3 購買失敗");
			}
			break;
		case 4:
			if(moneyin >= 10){
				printf("\n商品 4 購買完成，退幣 %d 元",moneyin-87);
			}
			else{
				printf("\n商品 4 購買失敗");
			}
			break;
		default:
			printf("\n你輸入了不存在的產品");
	}
	return 0;
} 
