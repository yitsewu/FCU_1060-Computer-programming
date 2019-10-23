#include<stdio.h>

int main(){
	int times, Input ,counter = 0;
	scanf("%d",&times);
	while(times--){
		while(scanf("%d",&Input) != EOF){
			counter = 0;
			while(1){
				if((Input=Input/3) < 3){
					counter++;
					break;
				}
				counter++;
			}
			printf("%d\n",counter+1);
		}
	}
	
	return 0;
}
