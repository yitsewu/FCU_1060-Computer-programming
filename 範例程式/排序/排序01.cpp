#include<stdio.h>

int main(){
	int i,j,tmp,sort[10]={8,5,2,7,4,1,9,6,3,0};
	for(i=0;i<10;i++){
		for(j=0;j<9-i;j++){
			if(sort[j] > sort[j+1]){
				tmp = sort[j];
				sort[j] = sort[j+1];
				sort[j+1] = tmp;
			}
		}
	}
	for(i=0;i<10;i++){
		printf("%2d",sort[i]);
	}
	return 0;
} 
