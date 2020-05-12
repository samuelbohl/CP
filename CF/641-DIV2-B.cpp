#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	vector<int> v(n+1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	vector<int> dp(n+1, 0); 
	int mx = 0;
	for(int i = 1; i <= n; ++i){
		dp[i] = max(1, dp[i]);
		for(int j = 1; j*i <= n; ++j){
			if(v[i*j] > v[i]) dp[i*j] = max(dp[i*j], dp[i]+1);
			mx = max(mx, dp[i*j]);
		}
	}
	
	cout << mx << "\n";
}
 
int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
	return 0;
}