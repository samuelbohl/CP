#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	
	string str;
	cin >> str;
	
	vector<bool> used(n, 0);
	stack<int> st;
	for(int i = 0; i < n; ++i){
		if(k == 0) break;
		if(str[i] == '('){
			st.push(i);
		} else {
			used[st.top()] = 1;
			used[i] = 1;
			st.pop();
			k-=2;
		}
	}
	for(int i = 0; i < n; ++i){
		if(used[i]) cout << str[i];
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