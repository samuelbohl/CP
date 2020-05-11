#include <bits/stdc++.h>

const int MAX_N = 3 * 1e5 +1;

long long a[MAX_N];
long long b[MAX_N];
int cnt;

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < m; ++i){
		scanf("%lld", &b[i]);
	}
	
	std::sort(a, a+n);
	std::sort(b, b+m);
	
	int l = 0;
	int r = 0;
	while(l < n && r < n){
		//assert(r < n);
		if(a[l] + k < b[r]){
			l++;
		} else if(a[l] - k > b[r]){
			r++;
		} else {
			cnt++;
			l++;
			r++;
		}
	}
	
	
	printf("%d", cnt);
	

	return 0;
}

