#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
	/*宣告區*/
	srand(time(NULL));
	int length = 100, type = 11, num[length][type], Row, Col, Check, team, sort, tmp;
	/*陣列初始化（預設值：-1）*/ 
	memset(num, -1, sizeof(num));
    /*亂數產生與重複值檢測*/ 
    for(Row = 0; Row < length ; Row++){
		num[Row][0]= (rand()%1000);
		for(Check = 0; Check < Row; Check++){
			if(num[Row][0] == num[Check][0]){
				num[Row][0]	= (rand()%1000);
				Check = -1;
			}
		}
	}
	/*值排序*/ 
	for(Row = length-1; Row >= 0; Row--){
		for(sort = Row; sort >= 0; sort--){
			if(num[sort][0] > num[Row][0]){
				tmp = num[sort][0];
				num[sort][0] = num[Row][0];
				num[Row][0] = tmp;
			}
		}
	}
	/*分群(陣列第一列來存基底資料，其餘用來分群)*/ 
	for(Row = 0; Row < length; Row++) {
        for(Col = 0; Col < type; Col++) {
            team = num[Row][0]%10;
            num[Row][team+1] = num[Row][0];
        }
    }
    /*輸出（以行的資料輸出，前面已經排序過，無須再排序，定義-1為空值，只讀出非空值的陣列元素）*/ 
    for(Col = 1; Col < type; Col++) {
    	printf("第%d群<尾數%d>:\n",Col,Col-1);
    	for(Row = 0; Row < length; Row++){
			if(num[Row][Col] != (-1)){
				printf("%3d ",num[Row][Col]);
			}
	   }
	   printf("\n\n");
    }
	return 0;
}
