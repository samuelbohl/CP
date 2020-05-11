#include <bits/stdc++.h>

const int MAX_N = 5001;


int main(){
	
	int t;
	scanf("%d", &t);
	
	long long x, y, res;
	while(t--){
		scanf("%lld %lld", &x, &y);
		if(x >= y){
			if(x % 2 == 0){
				res = x*x - (y-1);
			} else {
				res = (x-1)*(x-1) + 1 + (y-1);
			}
		} else {
			if(y % 2 == 0){
				res = (y-1)*(y-1) + 1 + (x-1);
			} else {
				res = y*y - (x-1);
			}
		}
		printf("%lld\n", res);
	}

	
	return 0;
}

