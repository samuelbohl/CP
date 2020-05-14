#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
const int INF = 1e9+1;
const int MAX_N = 101;

bool vis[MAX_N];
vector<int> g[MAX_N];

void dfs(int cur){
	vis[cur] = 1;
	for(int k : g[cur]){
		if(!vis[k]) dfs(k);
	}
}
 
void solve(){
	int n, m;
	cin >> n >> m;
	
	
	int a, c, cnt = 0;
	vi list[n];
	for(int i = 0; i < n; ++i){
		cin >> c;
		for(int j = 0; j < c; ++j){
			cin >> a;
			list[i].pb(a);
		}
		if(c == 0) cnt++;
		
	}
	
	//corner case : all employees speak 0 languages
	if(cnt == n){
		cout << n;
		return;
	}
	
	//connecting all employees sharing a language
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			if(i == j) continue;
			for(int k = 0; k < list[i].size(); ++k){
				for(int l = 0; l < list[j].size(); ++l){
					if(list[i][k] == list[j][l]){
						g[i].pb(j);
						g[j].pb(i);
					}
				}
			}
		}
	}
	cnt = 0;
	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt-1;
	
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