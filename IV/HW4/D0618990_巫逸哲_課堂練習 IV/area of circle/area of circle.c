#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
	FILE *inptr = NULL, *outptr = NULL;
	int r;
	float area;
	
	/* file pointer */
	inptr = fopen("text.txt", "r");
	outptr = fopen("output.txt", "a");
	
	
	if(inptr == NULL)return 0;
	
	fprintf(outptr, "\n");
	
	while( ( fscanf(inptr, "%d", &r)) != EOF){
		area = (float)r*r*M_PI;
		printf("radius : %3d, area : %.4f\n", r, area);
		fprintf(outptr, "radius : %3d, area : %.4f\n", r, area);
	}
		
	/* close file pointer*/
	fclose(inptr);
	fclose(outptr);
 
	return 0;
}



