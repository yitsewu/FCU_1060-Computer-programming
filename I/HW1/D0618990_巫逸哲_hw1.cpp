#include<stdio.h> 
/*��T�@�A D0618990 �Ŷh��*/
int main(){
	int CRcalculus,CRenglish,CRcomputer;/*�Ǥ����O���*/
	float GRcalculus,GRenglish,GRcomputer,CGcalculus,CGenglish,CGcomputer,sum,average;/*���Z�i��s�b0.5���A�ҥH�]�p���B�I��*/
	
	/*���Z�Ǥ���J��*/
	printf("--�п�J���Z--\n");
	printf("\n�L�n��:");
	scanf("%f",&GRcalculus);
	printf("\n �^�� :");
	scanf("%f",&GRenglish);
    printf("\n �p�� :");
	scanf("%f",&GRcomputer);
	
	printf("\n--�п�J�Ǥ�--\n");
	printf("\n�L�n��:");
	scanf("%d",&CRcalculus);
	printf("\n �^�� :");
	scanf("%d",&CRenglish);
    printf("\n �p�� :");
	scanf("%d",&CRcomputer);
	
	/*�B���*/
	CGcalculus = GRcalculus * CRcalculus;
	CGenglish = GRenglish * CRenglish;
	CGcomputer = GRcomputer*CRcomputer;
	
	sum = (CGcalculus) + (CGenglish) + (CGcomputer);
	average =  sum/(CRcalculus + CRenglish + CRenglish);
	
	/*��X��*/
	printf("\n\n��� :  �L�n��    �^��    �p��    �[�v�`��    �[�v����\n");
	printf("-----------------------------------------------------------------\n");
	printf("���Z :  %-3.1f      %-3.1f    %-3.1f    %.1f        %.2f\n",GRcalculus,GRenglish,GRcomputer,sum,average);
	printf("�Ǥ� :  %-3d       %-3d     %-3d\n",CRcalculus,CRenglish,CRenglish);
	printf("=================================================================\n");
	printf("�[�v :  %-3.1f      %-3.1f    %-3.1f\n",CGcalculus,CGenglish,CGcomputer); 
	
	return 0;
	
}
