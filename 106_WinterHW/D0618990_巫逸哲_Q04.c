#include<stdio.h>
#include<string.h>

int main(){
    int playertotal, numofplayer, team, temp[2], i, j, k;
    
    scanf("%d",&playertotal);
    
    double Player[4][playertotal];
    memset(Player, 0, sizeof(Player));
    (playertotal%8==0)?(team = playertotal/8):(team = playertotal/8+1);

    for(numofplayer = 0; numofplayer < playertotal; numofplayer++){
        scanf("%d %lf", &Player[0][numofplayer], &Player[1][numofplayer]);
    }
    
    for(i = 0; i < playertotal; i++){
		for(j = i; j < playertotal; j++){
			if(Player[1][j] > Player[1][i]){
				for(k = 0; k < 2;k++){
					temp[k] = Player[k][j];
					Player[k][j] = Player[k][i];
					Player[k][i] = temp[k];
				}
			}
		}
	}
    
//	printf("%d",team);
    
    return 0;
}
