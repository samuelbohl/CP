#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9+1;
const int MAX_N = 101;

int x[MAX_N];
int y[MAX_N];
bool vis[MAX_N];

void dfs(int cur){
	vis[cur] = true;
	for(int i = 1; i <= 100; ++i){
		if(vis[i] || i == cur) continue;
		if((x[i] < x[cur] && x[cur] < y[i]) || (x[i] < y[cur] && y[cur] < y[i])){
			dfs(i);
		}
	}
}

void solve(){
	int n, a, b, c;
	cin >> n;
	
	int p = 0;
	for(int i = 0; i < n; ++i){
		cin >> a >> b >> c;
		if(a == 1){
			p++;
			x[p] = b;
			y[p] = c;
		} else {
			memset(vis, 0, sizeof(vis));
			dfs(b);
			if(vis[c]){
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
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