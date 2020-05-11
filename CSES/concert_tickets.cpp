#include <bits/stdc++.h>

const int MAX_N = 2 * 1e5 +1;

std::multiset<int, std::greater<int>> h;
int t[MAX_N];
int cnt, l, r;



int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	int cur;
	for(int i = 0; i < n; ++i){
		scanf("%d", &cur);
		h.insert(cur);
	}
	
	for(int i = 0; i < m; ++i){
		scanf("%d", &t[i]);
	}
	
	for(int i = 0; i < m; ++i){		
		auto it = h.lower_bound(t[i]);
		if(it == h.end()){
			printf("-1\n");
		} else {
			printf("%d\n", *it);
			h.erase(it);
		}		
	}

	return 0;
}

