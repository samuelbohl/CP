#include <bits/stdc++.h> 
using namespace std;

typedef vector<int> vi;
 
const int INF = 1e9+1;
const int MAX_N = 101;
 
void solve(){
	int n, k;
	cin >> n >> k;
	
	vi v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	bool flag = 0, flag1 = 0, flag2 = 0;
	for(int i = 0; i < n-2; ++i){
		int equal = (v[i] == k) + (v[i+1] == k) + (v[i+2] == k);
		int smaller = (v[i] < k) + (v[i+1] < k) + (v[i+2] < k);
		int greater = (v[i] > k) + (v[i+1] > k) + (v[i+2] > k);
		
		if(greater >= 2) flag1 = 1;
		if(equal) flag2 = 1;
		
		if((equal && greater) || (equal >= 2) || (flag1 && flag2)){
			flag = 1;
			break;
		} 
		
	}
	if(n == 1 && v[0] == k){
		cout << "yes\n";
		return;
	}
	
	if(n == 2 && min(v[0], v[1]) == k){
		cout << "yes\n";
		return;
	}
	
	if(flag) cout << "yes\n";
	else cout << "no\n";
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