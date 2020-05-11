#include <bits/stdc++.h>

const int MAX_N = 2*1e5+1;
int h[MAX_N];

std::map<int, int> m;


int main(){
	
	

	int n, x;
	scanf("%d %d", &n, &x);
	
	for(int i = 0; i < n; ++i){
		scanf("%d ", &h[i]);

	}
	
	for(int i = 0; i < n; ++i){
		if(m.count(x-h[i])){
			printf("%d %d", m[x-h[i]], i+1);
			return 0;
		} else {
			m[h[i]] = i+1;
		}
	}

	
	
	
	printf("IMPOSSIBLE");
	


	
	return 0;
	
}

