#include <bits/stdc++.h>

const int MAX_N = 2 * 1e5 +1;

int a[MAX_N];
int b[MAX_N];
std::vector<int> c;
int cnt;

int main(){
	int n;
	scanf("%d", &n);
	
	int mx = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &a[i], &b[i]);
		mx = std::max(mx, std::max(a[i], b[i]));
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	
	std::sort(a, a+n);
	std::sort(b, b+n);
	std::sort(c.begin(), c.end());
	
	int l = 0; int r = 0; int cur = 0;
	for(int i = 0; i < c.size(); ++i){
		if(a[l] == c[i]){
			cur++; l++;
		}
		if(b[r] == c[i]){
			cur--; r++;
		}
		cnt = std::max(cnt, cur);
	}
	
	printf("%d", cnt);
	
	return 0;
}

