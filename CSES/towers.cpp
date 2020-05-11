#include <bits/stdc++.h>

const int MAX_N = 2*1e5+1;
int h[MAX_N];
std::multiset<int> s;

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i){
		scanf("%d ", &h[i]);
	}
	
	int t = 0;
	for(int i = 0; i < n; ++i){
		auto c = s.upper_bound(h[i]);
		if(c == s.end()){
			t++;
		} else s.erase(c);
		s.insert(h[i]);
	}
	
	printf("%d", t);
	
	return 0;
	
}

