#include<stdio.h>

//int main(){
//	int num,i,n,Ans;
//	scanf("%d",&num);
//	for(i = 1; i <= num; i++){
//		n = i;
//		if(i%2 == 1){
//			Ans = n + 2;
//		} else {
//			Ans = n + Ans; 
//		}
//		printf("%d ",Ans);
//	}
//	return 0;
//}

void f(int num){
	int i,n,Ans;
	for(i = 1; i <= num; i++){
		n = i;
		if(i%2 == 1){
			Ans = n + 2;
		} else {
			Ans = n + Ans; 
		}
		printf("%d ",Ans);
	}
}

int main(){
	int num;
	scanf("%d",&num);
	f(num);
	return 0;
}


