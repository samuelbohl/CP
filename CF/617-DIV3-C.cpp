#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
const int INF = 1e9+1;
const int MAX_N = 1e6+1;

void solve(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	
	map<pair<int, int>, int> m;
	pair<int, int> cur = {0,0};
	
	int pos = 0, mx = -1, l, r;
	while(pos <= n){
		if(m.count(cur)){ //if we already visited this point
			if(mx == -1 || mx > pos-m[cur]+1){
				l = m[cur]+1;
				r = pos;
				mx = pos-m[cur]+1;
			} 
		}
		
		if(pos == n) break;
		
		m[cur] = pos; //saving the last position of this point
		
		if(str[pos] == 'L') cur.fi--;
		else if(str[pos] == 'R') cur.fi++;
		else if(str[pos] == 'U') cur.se++;
		else if(str[pos] == 'D') cur.se--;
		pos++;
	}

	if(mx == -1) cout << mx << "\n";
	else cout << l << " " << r << "\n";
	
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