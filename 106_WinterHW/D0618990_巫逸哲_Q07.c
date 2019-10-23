#include<stdio.h>
#include<string.h>

int main(){
	int row, rowofInput, word, length = 50, Letter[2][26], check=0;
	memset(Letter, 0, sizeof(Letter));
	
	scanf("%d",&rowofInput);
	getchar();
	
	char InPut[rowofInput][length];
	memset(InPut, 0, sizeof(InPut));
	
	
	for(row = 0;row < rowofInput; row++){
		fgets(InPut[row], sizeof(InPut[row]), stdin);
	}
	
	for(row = 0; row < rowofInput; row++){
		for(word = 0; word < length; word++){
			if(InPut[row][word] >= 'A' && InPut[row][word] <= 'Z'){
				Letter[0][(InPut[row][word]%65)]++;
				Letter[1][(InPut[row][word]%65)]=1;
			} else if(InPut[row][word] >= 'a' && InPut[row][word] <= 'z'){
				Letter[0][(InPut[row][word]%97)]++;
				Letter[1][(InPut[row][word]%97)]=1;
			}
		}
	}
	
	for(word = 0; word < 26; word++){
		if(Letter[0][word]>check){
			check=Letter[0][word]; 
		}
	}
	
	for(word = 0; word < 26; word++){
		printf("%c %d\n",word+'A',Letter[0][word]);
	}


	
	printf("%d\n",check);
	
	for(word = 0; word < 26; word++){
		if(Letter[0][word]==check && Letter[1][word]==1){
			printf("%c %d\n",word+'A',Letter[word]);
			check--;
			word = -1;
		}
	}
	
	return 0;
} 
