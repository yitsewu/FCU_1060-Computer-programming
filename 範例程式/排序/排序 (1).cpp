#include<stdio.h>

int main(){
	int i,j,tmp,sort[10]={8,5,2,7,4,1,9,6,3,0};
	for(i=0;i<10;i++){
		for(j=i;j<10;j++){
			if(sort[j] > sort[i]){
				tmp = sort[j];
				sort[j] = sort[i];
				sort[i] = tmp;
			}
		}
	}
	for(i=0;i<10;i++){
		printf("%2d",sort[i]);
	}
	return 0;
} 
