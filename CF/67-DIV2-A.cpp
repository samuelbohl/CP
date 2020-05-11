#include <bits/stdc++.h>
#define all(cont) cont.begin(), cont.end()
 
using namespace std;

int remove_zero(int x){
	string str = to_string(x);
	reverse(all(str));
	x = 0; int exp = 1;
	for(int i = 0; i < str.length(); ++i){
		if(str[i] == '0') continue;
		x+= (str[i]-'0')*exp;
		exp*=10;
	}
	return x;
}

void solve(){
	int x, y;
	cin >> x >> y;
	int sum = x+y;
	
	x = remove_zero(x);
	y = remove_zero(y);
	sum = remove_zero(sum);
	
	if(x+y == sum) cout << "YES";
	else cout << "NO";
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