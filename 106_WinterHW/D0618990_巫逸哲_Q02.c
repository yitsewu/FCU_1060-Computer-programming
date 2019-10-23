#include<stdio.h>

int main(){
    int times, timesOfProgram, inPut, outPut, counter;
    
    scanf("%d",&timesOfProgram);

    for(times = 0; times < timesOfProgram; times++){
    	outPut = 1;
        scanf("%d",&inPut);
        for(counter = 1; counter < inPut; counter++){
        	outPut += counter;
		}
		printf("%d\n",outPut);
    }
    
    return 0;
}
