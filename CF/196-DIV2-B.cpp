#include <bits/stdc++.h>

using namespace std; 
typedef long long ll;
 
ll gcd(ll a,ll b){
	if(a<0)a=-a;
	if(b<0)b=-b;
	while(b!=0){
		a%=b;
		if(a==0)
			return b;
		b%=a;
	}
	return a;
}

void solve(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	//scaling to the same size
	ll p = a*d*b*d; 
	ll q = c*b*d*b;
	
	//corner case
	if(p == q){
		cout << "0/1";
		return;
	}
	
	//getting counter and determinator at right position
	if(p > q){
		ll temp = p;
		p = q;
		q = temp;
	}
	
	//reducing the fraction
	ll k = gcd(q, p);
	cout << q/k-p/k << "/" << q/k;
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