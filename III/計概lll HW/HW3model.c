#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bigint{
	unsigned int len;
	unsigned int space_size;
	unsigned char* val;
}bint;

typedef unsigned char uchar;

bint* newbint(){
}

void reverse(bint* tar){
}

void set(bint* tar){
}

bint* add(bint* a, bint* b){
}

void printbint(bint* tar){
}

int main(){
	bint* a = newbint(), *b = newbint();
	bint* c = NULL;
	while(1){
		set(a);
		if(a && a->len = 1 && a->val[0] = 0) break;
		set(b);
		if(c){
			free(c->val);
			free(c);
		}
		c = add(a, b);
		printbint(c);
		putchar('\n');
	}
	return 0;
}
