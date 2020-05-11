#include <bits/stdc++.h>

const int MAX_N = 2*1e5+1;
int h[MAX_N];
std::set<int> s;

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i){
		scanf("%d ", &h[i]);
	}
	
	int l = 0;
	int max = 0;
	for(int i = 0; i < n; ++i){
		if(s.count(h[i])){
			max = std::max(max, i-l);
			while(h[l] != h[i]){
				s.erase(h[l++]);
			}
			l++;
		} else s.insert(h[i]);
	}
	max = std::max(max, n-l);
	printf("%d", max);
	
	return 0;
	
}

