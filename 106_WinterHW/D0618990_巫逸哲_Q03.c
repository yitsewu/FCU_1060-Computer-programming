#include<stdio.h>
#include<string.h>

int main(){
    int times, timesOfProgram, workers = 10, numberOfWorker;
    
    scanf("%d",&timesOfProgram);
    
    int InPut[timesOfProgram][workers+1];
    memset(InPut, 0, sizeof(InPut));
    
    for(times = 0; times < timesOfProgram; times++){
    	for(numberOfWorker = 0; numberOfWorker < workers; numberOfWorker++){
    		scanf("%d",&InPut[times][numberOfWorker]);
		}
    }
    
    for(times = 0; times < timesOfProgram; times++){
    	for(numberOfWorker = 0; numberOfWorker < workers-1; numberOfWorker++){
    		if(InPut[times][numberOfWorker] < InPut[times][numberOfWorker+1]){
    			InPut[times][workers] = InPut[times][workers] - 1;
			} else {
				InPut[times][workers] = InPut[times][workers] + 1;
			}	
		}
    }
    
    printf("Lumberjacks:\n");
    
    for(times = 0; times < timesOfProgram; times++){
    	if(InPut[times][workers]==9 || InPut[times][workers]==-9){
    		printf("Ordered\n");
		} else {
			printf("Unordered\n");
		}
    }
    
    return 0;
}
