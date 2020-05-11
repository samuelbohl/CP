#include <bits/stdc++.h>

const int MAX_N = 1e9+2;

int cnt;


int main(){
	int n;
	scanf("%d", &n);
	
	int cur;
	std::set<int> s;
	for(int i = 0; i < n; ++i){
		scanf("%d", &cur);
		if(!s.count(cur)){
			s.insert(cur);
			++cnt;
		}
	}
	
	printf("%d", cnt);
	

	return 0;
}

