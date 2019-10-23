#include<stdio.h>
#include<string.h>

int main(){
    int a, b;
    
    scanf("%d",&b);
    
    int InPut[b],Ans[3];
    memset(InPut, 0, sizeof(InPut));
	memset(Ans, 0, sizeof(Ans));
	
	 for(a = 0; a < b; a++){
        scanf("%d",&InPut[a]);
    }
	
    for(a = 0; a < b; a++){
        if(InPut[a]%3==0){
        	Ans[0]++;
		} else if(InPut[a]%3==1) {
			Ans[1]++;
		} else if(InPut[a]%3==2) {
			Ans[2]++;
		}
    }
    
    printf("%d %d %d",Ans[0],Ans[1],Ans[2]);
    
    return 0;
}
