#include<stdio.h>
#include<string.h>

/*�w�q*/
#define BigIntLen 21
#define Times 5
 
int main(){
	/*�ŧi�ϡA�P�}�C��l��*/ /*Question: = {0} & memset ���t�O(�b�O�ƥ����Բӱԭz)*/ 
	int i,j,k,printCheck = 0,bigint[Times][BigIntLen] = {0};
	char Intputbigint[Times][BigIntLen] = {0},ans[BigIntLen] = {0};
	
	/*��J�P�H�Ӧ�Ƭ��D�v�@���*/ 
	for(i = 0; i < Times; i++){
		scanf("%s", Intputbigint[i]);
		for(j = 0, k = strlen(Intputbigint[i])-1; j < BigIntLen, k >= 0; j++, k--){
			bigint[i][j] = Intputbigint[i][k]-'0';
		}
	}
	
	/*�[�k�P�i��*/
	for(i = 0; i < BigIntLen; i++){
		for(j = 0; j < Times; j++){
			ans[i] += bigint[j][i];
		}
		if(ans[i]/10 != 0){
			ans[i+1] = ans[i]/10;
			ans[i] %= 10;
		}
	}
	
	/*��X��(Ans�}�C �ѱq�Ĥ@�Ӥ����s���ƶ}�l��X)*/ 
	printf("\n");
	for(i = BigIntLen-1; i >= 0; i--){
		if(ans[i] != 0 || printCheck != 0){
			printf("%c",ans[i]+'0');
			printCheck = 1;
		}
	} 
	return 0;
}
