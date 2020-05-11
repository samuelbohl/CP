#include <bits/stdc++.h>

const int MAX_N = 2 * 1e5 +1;

int p[MAX_N];
int cnt;

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	
	for(int i = 0; i < n; ++i){
		scanf("%d", &p[i]);
	}

	std::sort(p, p+n);
	
	int l = 0;
	int r = n-1;
	while(l <= r){
		if(p[l] + p[r] <= x){
			l++;
			r--;
			cnt++;
		} else if(p[r] <= x){
			r--;
			cnt++;
		} else {
			r--;
		}
	}
	
	
	printf("%d", cnt);
	

	return 0;
}

