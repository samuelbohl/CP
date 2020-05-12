#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; ++i){
		if(n%2 == 0){
			n+= (2*(k-i));
			break;
		}
		for(int j = 3; j <= n; j+=2){
			if(n%j == 0){
				n+=j;
				break;
			}
		}
	}
	cout << n << "\n";
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