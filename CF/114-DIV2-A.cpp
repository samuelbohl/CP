#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	double clones = 0;
	while((clones+x)/n*100 < y) clones++;
	cout << clones;
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