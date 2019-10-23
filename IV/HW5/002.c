#include<stdio.h>
#include<string.h>
#define MAX 10
 
int main(){
	int i, j, n, a, b, ab, input_1[MAX], input_2[MAX], check[MAX], AND, OR;
	float ans;
	
	scanf("%d",&n);
	
	while(n--){
		AND = 0;
		OR = 0;
		
		scanf("%d %d", &a, &b);
		
		for(i = 0; i < a; i++){
			scanf("%d",&input_1[i]);
		}
		for(i = 0; i < b; i++){
			scanf("%d",&input_2[i]);
		}
		
		for(i = 0; i < a; i++){
			for(j = 0; j < b; j++){
				if(input_1[i] == input_2[j]){
					AND++;
				}
			}
		}
		
		OR = a + b - AND;
		ans = (float)AND/OR;
		
		if(ans > 0.5){
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}
