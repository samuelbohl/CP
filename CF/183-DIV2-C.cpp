#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	//not possible for even n
	if(n%2 == 0){
		cout << -1;
		return;
	}
	
	for(int i = 0; i < n; ++i){
		cout << i << " ";
	}
	cout << "\n";
	
	for(int i = 0; i < n; ++i){
		cout << i << " ";
	}
	cout << "\n";
	
	for(int i = 0; i < n; ++i){
		cout << (i+i)%n << " ";
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