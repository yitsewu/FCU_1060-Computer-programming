#include "list.h"

int main(){
	FILE *inptr = NULL, *outptr = NULL;
	list head = createlist();
	
	char wordI, wordA = 0, wordB = 0;
	int i, Rcounter = 0, Ncounter = 0;
	int RN_flag, reof_flag;
	
	/* file pointer */
	inptr = fopen("test\\test1.txt", "r");
	outptr = fopen("testoutput\\output.txt", "w");
	
	if(inptr == NULL){
		printf("FILE Empty");
		return 0;	
	}
	
	
	/* Compressed */
	
	while(1){
		fscanf(inptr, "%c", &wordI);
		if(feof(inptr) != 0) reof_flag = 1;
		
		if(wordA == 0){
			wordA = wordI;
			continue;
		} else if(wordB == 0){
			wordB = wordI;
		} else if(reof_flag){
			wordA = wordB;
			wordB = 0;
		} else {
			wordA = wordB;
			wordB = wordI;
		}
	
		if(wordA == wordB){
			RN_flag = 0;
			if(Ncounter != 0){
				printlist(RN_flag, Ncounter-1, head);
			}
			
			for(i = Ncounter; Ncounter > 0; Ncounter--){
				qpopnode(&head);
			}
			Ncounter = 0;
			
			if(Rcounter == 0) pushnode(&head, wordA);
			Rcounter++;
		} else {
			RN_flag = 1;
			if(Rcounter != 0){
				printlist(RN_flag, Rcounter+1, head);
				qpopnode(&head);
			}
			Rcounter = 0;
			pushnode(&head, wordI);
			Ncounter++;
		}
		
		if(feof(inptr) != 0){
			if(isempty(head) != 0){
				break;
			}
			if(RN_flag == 1){
				if(Rcounter != 0){
					printlist(RN_flag, Rcounter, head);
					qpopnode(&head);
					break;
				}
				Rcounter == 0;
			} else if(RN_flag == 0){
				if(Ncounter == 0){
					break;
				}
			}
		}
		
	}
	
	return 0;
}
