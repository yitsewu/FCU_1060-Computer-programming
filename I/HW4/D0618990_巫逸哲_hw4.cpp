#include<stdio.h>
int main() {
    /*��J��*/
	 
	int num,i,j;
	printf("Please Input a Number:\n");
	scanf("%d",&num);
	
	/*�Ĥ@�ϧ�*/ 
	
	printf("\n(1)\n");
	
	for(i=0;i<num;i++){
    	
		printf("\n");
    	
    	for(j=num-1;j>=i+1;j--){
        	printf(".");
        }
    	for(j=0;j<=i;j++){
        	printf("*");
        }
        
        printf(" - %d"/*"��*"*/,i+1);
        
    }
    
    for(i=1;i<num;i++){
    	
		printf("\n");
    	
    	for(j=1;j<=i;j++){
        	printf(".");
        }
		for(j=num-1;j>=i;j--){
        	printf("*");
        }
        
		printf(" - %d"/*"��*"*/,num-i);
        
    }
	printf("\n");
	
	/*�ĤG�ϧ�*/ 
	
	printf("\n(2)\n");
	
	for(i=0;i<num;i++){
    	
		printf("\n");
    	
    	for(j=1;j<=i;j++){
        	printf(".");
        }
		for(j=num;j>i;j--){
        	printf("%d",num-i);
        }
        for(j=num;j>i;j--){
        	printf("%d",num-i);
        }
        for(j=1;j<=i;j++){
        	printf(".");
    	}
        
		//printf(" - %2d"/*"�ӼƦr"*/,(num-j+1)*2);
        
    }
    
    for(i=1;i<num;i++){
    	
		printf("\n");
    	
    	for(j=num;j>i+1;j--){
        	printf(".");
    	}
		for(j=1;j<=i+1;j++){
        	printf("%d",i+1);
        }
        for(j=1;j<=i+1;j++){
        	printf("%d",i+1);
    	}
    	for(j=num;j>i+1;j--){
        	printf(".");
        }
        
		//printf(" - %2d"/*"�ӼƦr"*/,j*2); 
		
    }
    
	printf("\n");
	
	return 0;
}
