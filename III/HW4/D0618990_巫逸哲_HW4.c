#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	int No;
	char Name[10];
	char Sex;
	int Math;
	int English;
	int Chinese;
	float Average;
}Student;

int main(){
	FILE *inptr = NULL, *number_outptr = NULL, *grade_outptr = NULL;
	
	int num = 0, i, j, check, Entercount = 0;
	char ch, title[50];
	Student tmp;

	/* file pointer */
	inptr = fopen("input.txt", "r");
	number_outptr = fopen("number.txt", "w");
	grade_outptr = fopen("grade.txt", "w");
	
	
	/* read file */
	if(inptr == NULL)	return 0;
	
	while(feof(inptr) == 0){
		fscanf(inptr, "%c", &ch);
		if(ch == '\n') Entercount++ ;
	}
	
	Entercount-=2;
	Student Input[Entercount];
	memset(Input, 0, sizeof(Input));
	
	inptr = fopen("input.txt", "r");
	
	for(i = 0; ; i++){
		fscanf(inptr, "%c", &title[i]);
		if(title[i] == '\n') {
			title[i] = '\0';
			break;
		}
	}
	
	for(i = 0;i < Entercount;i++){
		fscanf(inptr, "%d\t%s\t%c\t%d\t%d\t%d\n", &Input[i].No, Input[i].Name, &Input[i].Sex, &Input[i].Math, &Input[i].English, &Input[i].Chinese);
	}
	
	for(i = 0;i < Entercount; i++){
		Input[i].Average = ((float)(Input[i].Math + Input[i].English + Input[i].Chinese)/3);
	}
	
	/* write grade.txt file */
	for(i = 0; i < Entercount; i++){
		for(j = i; j < Entercount; j++){
			if(Input[j].Average > Input[i].Average){
				tmp = Input[j];
				Input[j] = Input[i];
				Input[i] = tmp;
			}
		}
	}
	
	for(i = 0; ; i++){
		if(title[i] != '\0'){
			fprintf(grade_outptr, "%c", title[i]);
		}
		if(title[i] == '\0') {
			fprintf(grade_outptr, "\tAverage\n");
			break;
		}
	}
	
	for(i = 0;i < Entercount;i++){
		fprintf(grade_outptr, "%d\t%s\t%c\t%d\t%d\t%d\t%.2f\n", Input[i].No, Input[i].Name, Input[i].Sex, Input[i].Math, Input[i].English, Input[i].Chinese, Input[i].Average);
	}
	
	/* write number.txt file */
	for(i = 0; i < Entercount; i++){
		for(j = i; j < Entercount; j++){
			if(Input[j].No < Input[i].No){
				tmp = Input[j];
				Input[j] = Input[i];
				Input[i] = tmp;
			}
		}
	}
	
	for(i = 0; ; i++){
		if(title[i] != '\0'){
			fprintf(number_outptr, "%c", title[i]);
		}
		if(title[i] == '\0') {
			fprintf(number_outptr, "\tAverage\n");
			break;
		}
	}
	
	for(i = 0;i < Entercount;i++){
		fprintf(number_outptr, "%d\t%s\t%c\t%d\t%d\t%d\t%.2f\n", Input[i].No, Input[i].Name, Input[i].Sex, Input[i].Math, Input[i].English, Input[i].Chinese, Input[i].Average);
	}
	
	/* close file pointer */
	fclose(inptr);
	fclose(number_outptr);
	fclose(grade_outptr);
	printf("Data Output Finished.\n");
	
	/* Search Student : */
	do{
		check = 0;
		printf("Search Student :");
		scanf("%d", &num);
		if(num == 0) return 0;
		for(i = 0;i < Entercount;i++){
			if(Input[i].No == num){
				printf("%d %s %c %d %d %d %.2f\n", Input[i].No, Input[i].Name, Input[i].Sex, Input[i].Math, Input[i].English, Input[i].Chinese, Input[i].Average);
				check = 1;
			}
		}
		if(check == 0) printf("Error\n");
	}while(num!=0);
}
