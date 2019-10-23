#include<stdio.h>

int main(){
	unsigned long long int A,B;
	scanf("%llu%llu",&A,&B);
	printf("%llu\n",(A^B));
	return 0;
}
