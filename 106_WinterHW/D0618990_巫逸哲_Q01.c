#include<stdio.h>
#include<string.h>

int main(){
    int times, timesOfProgram, i, check = 0;
    char input[11];

    memset(input, 0, sizeof(input));

    scanf("%d",&timesOfProgram);

    for(times = 0; times < timesOfProgram; times++){
        scanf("%s",input);
        for(i = 0; i < 10; i++){
            if(i == 0){
            	if(input[i] >= 'A' && input[i] <= 'H'){
            		input[i] -= 55;
				} else if(input[i] == 'I'){
					input[i] -= 39;
				} else if(input[i] >= 'J' && input[i] <= 'N'){
					input[i] -= 56;
				} else if(input[i] == 'O'){
					input[i] -= 44;
				} else if(input[i] >= 'P' && input[i] <= 'V'){
					input[i] -= 57;
				} else if(input[i] == 'W'){
					input[i] -= 55;
				} else if(input[i] >= 'X' && input[i] <= 'Z'){
					input[i] -= 58;
				}
                check += (input[i]/10 + (input[i]%10)*9);
            } else {
            	input[i] -= 48;
                check += input[i]*(9-i);
            }
        }
        
        check += input[0];
        
        if(check % 10 == 0){
            printf("real");
        } else {
            printf("fake");
        }
        
        printf("\n");

        check = 0;
    }
    
    return 0;
}
