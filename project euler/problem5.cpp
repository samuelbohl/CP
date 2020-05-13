#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
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

int lcm(int a, int b){
	return a*b/gcd(a, b);
}

int main(){	

	int last = 1;
	for(int i = 2; i <= 20; ++i){
		last = lcm(last, i);
	}
	cout << last;

	return 0;
}