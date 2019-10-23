#include<stdio.h>
#include<string.h>

int main(){
	int i, j, A, B;
	char number[2][5];
    memset(number, 0, sizeof(number));
    
	scanf("%s",&number[0]);
	
	for(;;){
		A = 0; B = 0;
		scanf("%s",&number[1]);
		for(i = 0; i < 4; i++){
			if(number[0][i] == number[1][i]){
				A++;
			}
		}
		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				if(number[0][i] == number[1][j]){
					B++;
				}
			}
		}
		
		B-=A;
		
		printf("%dA%dB\n", A, B);
		
		if(A == 4){
			return 0;
		}
	}
}
