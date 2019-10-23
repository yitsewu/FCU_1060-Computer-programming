#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct Coordinate{
	float x;
	float y;
}COORDINATE;

typedef struct Tringle{
	COORDINATE coor[3];
	float side[3];
	float half;
	float area;
	int num;
}TRINGLE;

int main(){
	int i, j;
	
	TRINGLE inPut[3];
	memset(inPut, 0, sizeof(inPut));
	TRINGLE tmp;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%f %f",&inPut[i].coor[j].x,&inPut[i].coor[j].y);
		}
		inPut[i].half = 0;
		inPut[i].num = i+1;
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(j < 2){
				inPut[i].side[j] = sqrt((inPut[i].coor[j].x - inPut[i].coor[j+1].x) * (inPut[i].coor[j].x - inPut[i].coor[j+1].x) + (inPut[i].coor[j].y - inPut[i].coor[j+1].y) * (inPut[i].coor[j].y - inPut[i].coor[j+1].y));
				printf("%f ",inPut[i].side[j] = sqrt((inPut[i].coor[j].x - inPut[i].coor[j+1].x) * (inPut[i].coor[j].x - inPut[i].coor[j+1].x) + (inPut[i].coor[j].y - inPut[i].coor[j+1].y) * (inPut[i].coor[j].y - inPut[i].coor[j+1].y)));
			} else if(j==2) {
				inPut[i].side[j] = sqrt((inPut[i].coor[j].x - inPut[i].coor[j-2].x) * (inPut[i].coor[j].x - inPut[i].coor[j-2].x) + (inPut[i].coor[j].y - inPut[i].coor[j-2].y) * (inPut[i].coor[j].y - inPut[i].coor[j-2].y));
				printf("%f ",inPut[i].side[j] = sqrt((inPut[i].coor[j].x - inPut[i].coor[j-2].x) * (inPut[i].coor[j].x - inPut[i].coor[j-2].x) + (inPut[i].coor[j].y - inPut[i].coor[j-2].y) * (inPut[i].coor[j].y - inPut[i].coor[j-2].y)));
			}
			inPut[i].half += inPut[i].side[j];
		}
		inPut[i].half /= 2;
		inPut[i].area = sqrt(inPut[i].half * (inPut[i].half - inPut[i].side[0]) * (inPut[i].half - inPut[i].side[1]) * (inPut[i].half - inPut[i].side[2]));
	}
			
	printf("\n排序前：\n");
	for(i = 0; i < 3; i++){
		printf("第%d組 area = %.2f  ", i+1, inPut[i].area);
		for(j = 0; j < 3; j++){
			printf("(%.f,%.f)", inPut[i].coor[j].x, inPut[i].coor[j].y);
		}
		printf("\n");
	}
	
	for(i = 0; i < 3; i++){
		for(j = i; j < 3; j++){
			if(inPut[j].area > inPut[i].area){
				tmp = inPut[j];
				inPut[j] = inPut[i];
				inPut[i] = tmp;
			}
		}
	}
	
	printf("\n排序後：\n");
	for(i = 0; i < 3; i++){
		printf("第%d組 area = %.2f  ", inPut[i].num, inPut[i].area);
		for(j = 0; j < 3; j++){
			printf("(%.f,%.f) ", inPut[i].coor[j].x, inPut[i].coor[j].y);
		}
		printf("\n");
	}
	
	return 0;
} 
