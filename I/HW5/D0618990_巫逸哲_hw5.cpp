#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*�Ĥ@����*/ 
int main(){
	/*�ܼƳ]�w��*/ 
	int i,j,IntputNum[30],LineChange = 0,SameCheck;
	float IntputNumCheck[30];
	
	/*�H����l�ȳ]�w*/ 
	srand(time(NULL));
	
	/*Input*/ 
	printf("�п�J������ơA�ƭȽd��(1~100)�A�ƶq�̦h���W�L30�ӡA�Y��J0�h����:\n\n");
	
	i = 0;//( ���j�鱱���k�s)
    j = 0;//( ���j�鱱���k�s)
    
	while(i >= 0 && i < 30){
		scanf("%f",&IntputNumCheck[i]);
		IntputNum[i] = (int)IntputNumCheck[i];
		
		if(IntputNumCheck[i] - IntputNum[i] != 0){
			printf("[Error!](�D���)�A�Э��s��J:\n");
		} //( ����J�p�ƭ��s��J����Ai���i��A�h��J�ȱN�����л\���~��)
		else if(IntputNum[i] == 0){
			break;
		}//( ����J0��������)
		else if(IntputNum[i] < 1 || IntputNum[i] > 100){
			
			printf("[Error!](���b1~100��)�A�t�αN�۰ʥͦ�:\n");
			IntputNum[i] = (rand()%100)+1;
			printf("%d\n",IntputNum[i]);
			
			for(SameCheck = 0;SameCheck < i;SameCheck++){
				if(IntputNum[i] == IntputNum[SameCheck]){
					printf("[Error!](�P�e��Ʀr����)�A�t�αN�۰ʥͦ�:\n");
					IntputNum[i] = (rand()%100)+1;
					printf("%d",IntputNum[i]);
					printf("\n���s�˴�\n");
					SameCheck = -1; //( �����Ұj��A���ҥH�Ϭ�-1����]���j�鵲����|���W�i��++�A�ҥH���ର0)
				}
			}//( �����ƭ��˴��A���߫h�۰ʶüƼg�J)
			
			printf("�����ơA���~���J\n");
			i++;
		}//( ����J�W�X�d��۰ʶüƼg�J)
		else{
			for(SameCheck = 0;SameCheck < i;SameCheck++){
				if(IntputNum[i] == IntputNum[SameCheck]){
					printf("[Error!]���~(�P�e��Ʀr����)�A�t�αN�۰ʥͦ�:\n");
					IntputNum[i] = (rand()%100)+1;
					printf("%d",IntputNum[i]);
					printf("\n���s�˴�\n");
					SameCheck = -1;//( �����Ұj��A���ҥH�Ϭ�-1����]���j�鵲����|���W�i��++�A�ҥH���ର0)
				}
			}//( �����ƭ��˴��A���߫h�۰ʶüƼg�J)
			printf("�����ơA���~���J\n");
			i++;
		}
	}
	
	j = i;//( ������J����)
	
	if(i < 30){
		printf("��J�Ʀr���F30�ӡA�t�αN�۰ʥͦ�:\n");
		for (i = j; i < 30; i++) {
        	IntputNum[i] = (rand()%100)+1;
        	printf("%d\n",IntputNum[i]);
        	for(SameCheck = 0;SameCheck < i;SameCheck++){
				if(IntputNum[i] == IntputNum[SameCheck]){
					printf("[Error!]���~(�P�e��Ʀr����)�A�t�αN�۰ʥͦ�:\n");
					IntputNum[i] = (rand()%100)+1;
					printf("%d",IntputNum[i]);
					printf("\n���s�˴�\n");
					SameCheck = -1;//( �����Ұj��A���ҥH�Ϭ�-1����]���j�鵲����|���W�i��++�A�ҥH���ର0)
				}
			}//( �����ƭ��˴��A���߫h�۰ʶüƼg�J)
			printf("�����ơA���~���J\n");
    	}
	}
	
	
	/*Output*/

	i = 0;//( ������j���k�s)
	
	while(i >= 0 && i < 30){
		//(�@�~�@�\�� : ���J 0 �ɵ���(���t 0)�C�����ɦL�X��J���Ҧ��Ʀr�C)
		//( ���Y�n�N�אּ0������X�A�h�N�W�� i < 30 �אּ j - 1�� ��)
		printf("%5d",IntputNum[i]);
		i++;
		LineChange++;//( �����汱��j��)
		if(LineChange == 10){
			printf("\n");
			LineChange = 0;
		}
	}
	return 0;
}
