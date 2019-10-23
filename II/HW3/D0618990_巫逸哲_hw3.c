#include<stdio.h>
#include<string.h>

/*定義*/
#define BigIntLen 21
#define Times 5
 
int main(){
	/*宣告區，與陣列初始化*/ /*Question: = {0} & memset 的差別(在記事本有詳細敘述)*/ 
	int i,j,k,printCheck = 0,bigint[Times][BigIntLen] = {0};
	char Intputbigint[Times][BigIntLen] = {0},ans[BigIntLen] = {0};
	
	/*輸入與以個位數為主逐一對齊*/ 
	for(i = 0; i < Times; i++){
		scanf("%s", Intputbigint[i]);
		for(j = 0, k = strlen(Intputbigint[i])-1; j < BigIntLen, k >= 0; j++, k--){
			bigint[i][j] = Intputbigint[i][k]-'0';
		}
	}
	
	/*加法與進位*/
	for(i = 0; i < BigIntLen; i++){
		for(j = 0; j < Times; j++){
			ans[i] += bigint[j][i];
		}
		if(ans[i]/10 != 0){
			ans[i+1] = ans[i]/10;
			ans[i] %= 10;
		}
	}
	
	/*輸出區(Ans陣列 由從第一個不為零的數開始輸出)*/ 
	printf("\n");
	for(i = BigIntLen-1; i >= 0; i--){
		if(ans[i] != 0 || printCheck != 0){
			printf("%c",ans[i]+'0');
			printCheck = 1;
		}
	} 
	return 0;
}
