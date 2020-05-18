#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	
	int a, b;
	vector<bool> v(n+1, 1);
	for(int i = 0; i < m; ++i){
		cin >> a >> b; // those cant be center points
		v[a] = 0;
		v[b] = 0;
	}
	
	//find center point
	int c = 0;
	for(int i = 1; i <= n; ++i){
		if(v[i]){
			c = i;
			break;
		}
	}
	//print everything connected to center
	cout << n-1 << "\n";
	for(int i = 1; i <= n; ++i){
		if(i == c) continue;
		cout << c << " " << i << "\n";
	}
	
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