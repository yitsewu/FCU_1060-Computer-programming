#include<stdio.h>

double Power(int x, int y){
	if(y == 0){
		return 1;
	} else {
		return x*Power(x,y-1);
	}
}

double Factorial(int y){
	if(y == 1){
		return 1;
	} else {
		return y*Factorial(y-1);
	} 
}

double Count(int x,int y){
	return (double)Power(x,y)/(double)Factorial(y);
}

int main(){
	int x, y, yMax;
	double Ans;
	
	printf("½Ð¿é¤J(X,Y):\n");
	scanf("%d %d",&x,&yMax);
	
	for(y=1; y <= yMax; y++){
		Ans += (double)Count(x,y);
	}
	
	printf("%lf\n",Ans);
	return 0; 
} 
