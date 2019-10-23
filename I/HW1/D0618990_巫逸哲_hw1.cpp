#include<stdio.h> 
/*資訊一乙 D0618990 巫逸哲*/
int main(){
	int CRcalculus,CRenglish,CRcomputer;/*學分都是整數*/
	float GRcalculus,GRenglish,GRcomputer,CGcalculus,CGenglish,CGcomputer,sum,average;/*成績可能存在0.5分，所以設計成浮點數*/
	
	/*成績學分輸入區*/
	printf("--請輸入成績--\n");
	printf("\n微積分:");
	scanf("%f",&GRcalculus);
	printf("\n 英文 :");
	scanf("%f",&GRenglish);
    printf("\n 計概 :");
	scanf("%f",&GRcomputer);
	
	printf("\n--請輸入學分--\n");
	printf("\n微積分:");
	scanf("%d",&CRcalculus);
	printf("\n 英文 :");
	scanf("%d",&CRenglish);
    printf("\n 計概 :");
	scanf("%d",&CRcomputer);
	
	/*運算區*/
	CGcalculus = GRcalculus * CRcalculus;
	CGenglish = GRenglish * CRenglish;
	CGcomputer = GRcomputer*CRcomputer;
	
	sum = (CGcalculus) + (CGenglish) + (CGcomputer);
	average =  sum/(CRcalculus + CRenglish + CRenglish);
	
	/*輸出區*/
	printf("\n\n科目 :  微積分    英文    計概    加權總分    加權平均\n");
	printf("-----------------------------------------------------------------\n");
	printf("成績 :  %-3.1f      %-3.1f    %-3.1f    %.1f        %.2f\n",GRcalculus,GRenglish,GRcomputer,sum,average);
	printf("學分 :  %-3d       %-3d     %-3d\n",CRcalculus,CRenglish,CRenglish);
	printf("=================================================================\n");
	printf("加權 :  %-3.1f      %-3.1f    %-3.1f\n",CGcalculus,CGenglish,CGcomputer); 
	
	return 0;
	
}
