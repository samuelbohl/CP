#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;

const int MAX_N = 5001;

ll dp[MAX_N][MAX_N];
 
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vll pre(n+1, 0);
	ll a;
	for(int i = 1;i <= n; ++i){
		cin >> a;
		pre[i] = pre[i-1]+a;
		
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			dp[i][j] = max(dp[i-1][j], dp[max(i-m, 0)][j-1]+(pre[i]-pre[max(i-m, 0)]));
		}
	}
	cout << dp[n][k];
	
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