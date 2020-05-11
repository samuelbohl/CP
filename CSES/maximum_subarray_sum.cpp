#include <bits/stdc++.h>

const int MAX_N = 2*1e5+1;
long long h[MAX_N];

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i){
		scanf("%lld ", &h[i]);

	}
	long long sum = -100000, pre = 0;
	for(int i = 0; i < n; ++i){
		pre = std::max(pre + h[i], h[i]);
		if(pre >= sum){
			sum = pre;
		}
	}

	printf("%lld", sum);
	
	return 0;
	
}

