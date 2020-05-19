#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll fpow(ll x, ll y){
	ll t;
	if(y==0)return 1;
	t=fpow(x,y/2);
	if(y%2==0)return t*t;
	else return x*t*t;
}


ll sumOfDigits(ll x){
	ll sum = 0;
	while (x != 0){
        sum = sum + x % 10;
        x = x / 10;
    }
    return sum;
}

void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
	vector<ll> v;
	for(ll i = 1; i <= 81; ++i){
		if(b*fpow(i, a)+c >= (ll)1e9) continue;
		if(i == sumOfDigits(b*fpow(i, a)+c)){
			v.pb(b*fpow(i, a)+c);
		}
	}
	cout << v.size() << "\n";
	
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
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