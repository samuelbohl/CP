#include <bits/stdc++.h>

const int MAX_N = 1001;

int g[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int c;

void dfs(int x, int y){
	if(!vis[x][y]){
		vis[x][y] = true;
		
		if(x >= 1 && !vis[x-1][y] && g[x-1][y]){
			dfs(x-1, y);
		}
		if(y >= 1 && !vis[x][y-1] && g[x][y-1]){
			dfs(x, y-1);
		}
		if(x < MAX_N && !vis[x+1][y] && g[x+1][y]){
			dfs(x+1, y);
		}
		if(y < MAX_N && !vis[x][y+1] && g[x][y+1]){
			dfs(x, y+1);
		}
	}
}


int main(){
	
	int n, m;
	scanf("%d %d \n", &n, &m);
	
	char s;
	for(int i = 0; i < n; ++i){

		for(int j = 0; j < m; ++j){
			if(s == '.'){
				g[i][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(g[i][j] && !vis[i][j]){
				c++;
				dfs(i, j);
			}
		}
	}
	
	printf("%d\n", c);
	
	
	
	return 0;
}

