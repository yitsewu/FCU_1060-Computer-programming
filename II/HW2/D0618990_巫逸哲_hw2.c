#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
	/*�ŧi��*/
	srand(time(NULL));
	int length = 100, type = 11, num[length][type], Row, Col, Check, team, sort, tmp;
	/*�}�C��l�ơ]�w�]�ȡG-1�^*/ 
	memset(num, -1, sizeof(num));
    /*�üƲ��ͻP���ƭ��˴�*/ 
    for(Row = 0; Row < length ; Row++){
		num[Row][0]= (rand()%1000);
		for(Check = 0; Check < Row; Check++){
			if(num[Row][0] == num[Check][0]){
				num[Row][0]	= (rand()%1000);
				Check = -1;
			}
		}
	}
	/*�ȱƧ�*/ 
	for(Row = length-1; Row >= 0; Row--){
		for(sort = Row; sort >= 0; sort--){
			if(num[sort][0] > num[Row][0]){
				tmp = num[sort][0];
				num[sort][0] = num[Row][0];
				num[Row][0] = tmp;
			}
		}
	}
	/*���s(�}�C�Ĥ@�C�Ӧs�򩳸�ơA��l�ΨӤ��s)*/ 
	for(Row = 0; Row < length; Row++) {
        for(Col = 0; Col < type; Col++) {
            team = num[Row][0]%10;
            num[Row][team+1] = num[Row][0];
        }
    }
    /*��X�]�H�檺��ƿ�X�A�e���w�g�ƧǹL�A�L���A�ƧǡA�w�q-1���ŭȡA�uŪ�X�D�ŭȪ��}�C�����^*/ 
    for(Col = 1; Col < type; Col++) {
    	printf("��%d�s<����%d>:\n",Col,Col-1);
    	for(Row = 0; Row < length; Row++){
			if(num[Row][Col] != (-1)){
				printf("%3d ",num[Row][Col]);
			}
	   }
	   printf("\n\n");
    }
	return 0;
}
