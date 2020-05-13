#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef vector<int> vi;

//simple brute force solution
void solve(){
	int n;
	cin >> n;
	
	int k1, k2;
	cin >> k1; vi q1(k1);
	for(int i = 0; i < k1; ++i){
		cin >> q1[i];
	}
	
	cin >> k2; vi q2(k2);
	for(int i = 0; i < k2; ++i){
		cin >> q2[i];
	}
	
	set<pair<vi, vi>> states;
	states.insert({q1, q2}); // save initial state
	int cnt = 0, p = 0;
	while(1){
		//"play"
		if(q1[0] > q2[0]){
			q1.pb(q2[0]);
			q1.pb(q1[0]);
		} else {
			q2.pb(q1[0]);
			q2.pb(q2[0]);
		}
		q2.erase(q2.begin(), q2.begin() +1);
		q1.erase(q1.begin(), q1.begin() +1);
		
		cnt++;
		//determine if a player has won
		if(q1.size() == 0){
			p = 2;
			break;
		} else if(q2.size() == 0){
			p = 1;
			break;
		}
		//check if state already happened
		if(states.count({q1, q2})){
			cout << -1;
			return;
		}
		//save state
		states.insert({q1, q2});
	}
	
	cout << cnt << " " << p;
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