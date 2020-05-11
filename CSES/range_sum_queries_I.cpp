#include <bits/stdc++.h>

const int MAX_N = 200001;
long long arr[MAX_N];
long long s[MAX_N];


int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);
	
	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &arr[i]);
	}
	
	for(int i = 1; i <= n; ++i){
		s[i] = s[i-1] + arr[i];
	}
	

	int a, b;
	while(q--){
		
		scanf("%d %d", &a, &b);
		printf("%lld\n", s[b] - s[a-1]);
	}
	
	return 0;
}

