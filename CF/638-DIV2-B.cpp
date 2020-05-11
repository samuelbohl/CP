#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+1;
const int MAX_N = 101;

bool occ[MAX_N]; //to check if a value already occured

void solve(){
	int n, k;
	cin >> n >> k;
	
	vi v(n);
	int cnt = 0; //count the number of different values
	memset(occ, 0, sizeof(occ));
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		if(!occ[v[i]]) cnt++;
		occ[v[i]] = 1;
	}
	
	if(cnt > k){ //impossible
		cout << "-1\n";
		return;
	}
	
	//if we have less values than we need
	int h = 1;
	while(cnt < k){
		if(!occ[h]){
			cnt++;
			occ[h] = 1;
		}
		h++;
	}
	
	cout << n*k << "\n";
	
	//printing n times k distinct values
	for(int i = 0; i < n; ++i){
		for(int j = 1; j <= 100; ++j){
			if(occ[j]) cout << j << " ";
		}
	}
	cout << "\n";
	
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