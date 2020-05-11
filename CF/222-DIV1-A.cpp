#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 502;
bool vis[MAX_N][MAX_N];
int maze[MAX_N][MAX_N];
int cnt; //number of walls

//dfs to place the walls
void dfs(int x, int y){
	if(cnt <= 0) return;
	vis[x][y] = 1;
	
	if(maze[x][y+1] && !vis[x][y+1]) dfs(x, y+1);
	if(maze[x+1][y] && !vis[x+1][y]) dfs(x+1, y);
	if(maze[x-1][y] && !vis[x-1][y]) dfs(x-1, y);
	if(maze[x][y-1] && !vis[x][y-1]) dfs(x, y-1);
	
	//setting the wall
	if(cnt <= 0) return;
	maze[x][y] = 2;
	cnt--;
}

void solve(){
	int n, m;
	cin >> n >> m >> cnt;
	
	//reading maze
	string str;
	int startx, starty;
	for(int i = 1; i <= n; ++i){
		cin >> str;
		for(int j = 1; j <= m; ++j){
			maze[i][j] = (str[j-1] == '.');
			
			//save last known coordinates for dfs start
			if(maze[i][j]){
				startx = i;
				starty = j;
			}	
		}
	}
	
	//place walls from the end with dfs
	dfs(startx, starty);
	
	//print new maze
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(maze[i][j] == 2) cout << 'X';
			else if(maze[i][j]) cout << '.';
			else cout << '#';
		}
		cout << "\n";
	}
}
 
int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
	return 0;
}