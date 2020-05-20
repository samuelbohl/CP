#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef vector<int> vi;
const int MAX_N = 100001;


double p[MAX_N];
vi adj[MAX_N];

void dfs(int v, int par){
	int cnt = 0;
	for(int c : adj[v]){
		if(c != par) cnt++;
	}
	for(int c : adj[v]){
		if(c != par){ 
			p[c] = p[v]*(1.0/((double)cnt));
			dfs(c, v);
		}
	}
}

 
void solve(){
	int n;
	cin >> n;
	int u, v;
	for(int i = 1; i < n; ++i){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	p[1] = 1;
	dfs(1, 1);
	double sum = 0;
	for(int i = 2; i <= n; ++i){
		sum += p[i];
	}
	
	printf("%.7f", sum);
}
 
int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int i = 1, t = 1;
	//cin >> t;
	while(i <= t){
		//cout << "CASE #" << i << ": ";
		solve();
		i++;
	}	
	return 0;
}