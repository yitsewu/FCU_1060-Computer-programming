#include<stdio.h>
#include<math.h>

int main(){
    int times, timesOfProgram, check, Ans = 0;
	float A, B;

    scanf("%d",&timesOfProgram);

    for(times = 0; times < timesOfProgram; times++){
        scanf("%f %f",&A,&B);
        
		for(;A <= B;A++){
			check = sqrt(A);
			if((sqrt(A) - check) == 0){
				Ans += A;
			}
		}
		
		printf("%d\n",Ans);
		
		Ans = 0;
    }
    
    return 0;
}
