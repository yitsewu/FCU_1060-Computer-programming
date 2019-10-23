#include<stdio.h>
#include<string.h>
#define MAX 110

typedef struct SET{
	char word;
	int flag;
}SET;
 
int main(){
	int times, a, b, i, j, check, flag = 1;
	char SET;
	SET DNA[MAX][MAX];
	SET ANS[MAX][MAX];
	
//	scanf("%d",&times);
//	while(times--){
		memset(DNA, 0, sizeof(DNA));
		scanf("%d %d", &a, &b);
		for(i = 0; i < a; i++){
			for(j = 1; j <= b; j++){
				scanf("%c", &DNA[i][j].word);
				DNA[i][j].flag = 0;
			}
		}
		
		for(i = 0; i < a; i++){
			check = 0;
			
			for(j = 1; j < b; j++){
				if(DNA[i][j].word <= DNA[i][j+1].word){
					check++;
				} else{
					DNA[i][j].flag = 1;
					flag = 1;
				}
			}
			
			while(1){	
				if(flag == 1){
					for(j = 1; j < b; j++){
						if(DNA[i][j].flag == 1){
							for(; j < b; j++){
								if(DNA[i][j].word <= DNA[i][j+1].word){
									check++;
								} else {
									DNA[i][j].flag = 1;
									flag = 1;
								}
								
							}
						} else{
							flag = 1;
						}
					}
				}
			}
			
			printf("%d",check);
		}
//	}
	return 0;
	
//	
}
