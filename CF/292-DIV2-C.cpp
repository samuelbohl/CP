#include <bits/stdc++.h>
#define all(cont) cont.begin(), cont.end()

using namespace std;

void solve(){
	int n;
	cin >> n;
	
	string str, sol;
	cin >> str;
	
	for(int i = 0; i < n; ++i){
		if(str[i] == '0' || str[i] == '1') continue;
		if(str[i] == '2') sol.append("2");
		else if(str[i] == '3') sol.append("3");
		else if(str[i] == '4') sol.append("322");
		else if(str[i] == '5') sol.append("5");
		else if(str[i] == '6') sol.append("53");
		else if(str[i] == '7') sol.append("7");
		else if(str[i] == '8') sol.append("7222");
		else if(str[i] == '9') sol.append("7332");
	}
	
	sort(all(sol));
	reverse(all(sol));
	cout << sol;
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