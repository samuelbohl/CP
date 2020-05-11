#include <bits/stdc++.h>

const int MAX_N = 8;

char str[8][8];
bool col[8];
bool d1[16];
bool d2[16];
int count;

void search(int y){
	if(y == 8){
		++count;
	} else {
		for(int x = 0; x < 8; ++x){
			if(col[x] || d1[x+y] || d2[x-y+7] || str[x][y] != '.') {
				continue;
			}
			col[x] = d1[x+y] = d2[x-y+7] = true;
			search(y+1);
			col[x] = d1[x+y] = d2[x-y+7] = false;	
		}
	}
}



int main(){
	
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			scanf(" %c", &str[i][j]);		
		}
	}
	

	search(0);
	//chose(0, 0, row, col);
	

	
	
	printf("%d", count);
	

	return 0;
}

