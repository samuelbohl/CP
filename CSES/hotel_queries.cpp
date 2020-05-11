#include <bits/stdc++.h>

const int MAX_N = 200001;
long long t[4*MAX_N];
long long arr[MAX_N];
long long r[MAX_N];

int build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = arr[tl];
	} else {
		
		int mid = (tl+tr)/2;
		build(v*2, tl, mid);
		build(v*2+1, mid+1, tr);
		t[v] = std::max(t[v*2], t[v*2+1]);
	}
	
}

int update(long long g, int v, int tl, int tr){
	if(tl == tr){
		if(t[v] >= g){
			t[v] -= g;
			return tl;
		}
		
		return 0;
	}
	
	int mid = (tl+tr)/2;
	int res;
	if(t[v*2] >= g){
		res = update(g, v*2, tl, mid);
	} else  if (t[v*2+1] >= g){
		res = update(g, v*2+1, mid+1, tr);
	} else {
		res = 0;
	}
		
	t[v] = std::max(t[v*2], t[v*2+1]);
	return res;
}


int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &arr[i]);
	}
	
	for(int i = 0; i < m; ++i){
		scanf("%lld", &r[i]);
		
	}
	
	build(1, 1, n);
	
	
	for(int i = 0; i < m; ++i){
		printf("%d ", update(r[i], 1, 1, n) );
	}
	
	return 0;
}

