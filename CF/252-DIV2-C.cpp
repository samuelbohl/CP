#include <bits/stdc++.h>
using namespace std;

int curx = 1;
int cury = 1;

//"dfs" for tubing
void dfs(int x, int m){
	
	cout << x << " ";
	while(x--){
		cout << curx << " " << cury << " ";
		if(curx%2 == 1){
			if(cury < m) cury++;
			else curx++;
		}else{
			if(cury > 1) cury--;
			else curx++;
		}
	}
	cout << "\n";
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	
	
	//running tubes for first k-1 tubes of langth 2
	for(int i = 0; i < k-1; ++i){
		dfs(2, m);
	}
	//rest is for the last tube
	dfs(n*m-(2*(k-1)), m);
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