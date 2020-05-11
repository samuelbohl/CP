#include <bits/stdc++.h>

const int MAX_N = 1000001;
const int mod = 1e9 + 7;

long long f[MAX_N];

void fact(int x){
	f[0] = 1;
	for(int i = 1 ; i <= x; ++i){
		f[i] = (f[i-1] * i) % mod;
	}
}

long long pow(long long base, int exp)
{
	long long res = 1;
	for (; exp; exp >>= 1)
	{
		if (exp & 1) res = res * base % mod;
		base = base * base % mod;
	}
	return res;
}

int main(){
	
	int n;
	scanf("%d", &n);
	fact(MAX_N-1);
	
	long long a, b;
	while(n--){
		scanf("%lld %lld", &a, &b);

		printf("%lld\n", f[a] * pow((f[b]*f[a-b] % mod), mod-2) % mod);
	}

	
	return 0;
}

