#include<stdio.h>
#define max 30
typedef const int cint;
int main(){
	cint arr[max]={1,3,5,7,9,30,28,26,24,22,20,2,4,6,8,10,29,27,25,23,21,11,13,15,17,19,18,16,14,12};
	cint* ptr[max];
	int i,j,min,k,ct=-1;
	for(i=0;i<max;i++){
		min=10000;		 
		for(j=0;j<max;j++)
			if(arr[j]<min&&arr[j]>ct)	min=arr[j],k=j;	//找最小的而且比之前的大。 
		ct=arr[k];
		printf("%d ",*(ptr[i]=&arr[k]));  //試了邊存邊print結果能耶！！ 
	}
	return 0;
}
