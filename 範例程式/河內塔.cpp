#include <stdio.h>

void hannoi(int n, char from, char buffer, char to){
	if (n == 1){ //�������
		printf("Move disk %d from %c to %c\n", n, from, to);
	} else {
		hannoi(n-1, from, to, buffer); //���j
		printf("Move disk %d from %c to %c\n", n, from, to);        
		hannoi(n-1, buffer, from, to); //���j
	}
}
int main(){
	int n = 1;
	hannoi (n, 'A', 'B', 'C');
	return 0;
} 
