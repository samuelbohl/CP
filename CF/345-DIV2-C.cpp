#include <bits/stdc++.h>
#define all(cont) cont.begin(), cont.end()

using namespace std;
typedef vector<int> vi;
 
void solve(){
	int n;
	cin >> n;

	vi x(n), y(n);
	map<pair<int, int>, ll> m;
	for(int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
		m[{x[i],y[i]}]++; //for counting multiples
	}
	sort(all(x));
	sort(all(y));
	
	//counting all pairs of points that share a common axis
	ll cnt = 1, cnt2 = 1, ans =0;
	for(int i = 1; i <= n; ++i){
		if(i < n && x[i] == x[i-1]) cnt++;
		else{
			ans += cnt*(cnt-1)/2;
			cnt = 1;
		}
		if(i < n && y[i] == y[i-1]) cnt2++;
		else{
			ans += cnt2*(cnt2-1)/2;
			cnt2 = 1;
		}
	}
	
	//subtracting the overlapping points
	for(auto k : m){
		if(k.se > 1) ans -= (k.se)*(k.se-1)/2;
	}
	
	cout << ans;
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