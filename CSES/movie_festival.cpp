#include <bits/stdc++.h>

const int MAX_N = 1e6+1;

std::vector<std::pair<int, int>> s;

int main(){
	
	int n;
	scanf("%d", &n);
	
	int x, y;
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &x, &y);
		s.push_back({y, x});
	}
	
	std::sort(s.begin(), s.end());
	int cur = 0, cnt = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i].second >= cur){
			cur = s[i].first;
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
	
}

