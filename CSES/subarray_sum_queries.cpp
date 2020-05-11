#include <bits/stdc++.h>

struct data{long long t, m, l, r;};

const int MAX_N = 200001;
data st[4*MAX_N];

data merge(data lf, data rg){
	long long t = lf.t + rg.t;
	long long mid = std::max(std::max(std::max(lf.m, rg.m), lf.r + rg.l), t);
	long long lft = std::max(lf.l, lf.t + rg.l);
	long long rgt = std::max(rg.r, rg.t + lf.r);
	
	return {t, mid, lft, rgt};
}

 
void update(int ind, long long k, int v, int tl, int tr){
	if(ind < tl || ind > tr){
		return;
	}
	if(tl == tr && tr == ind){
		st[v] = {k, k, k, k};
	} else {
		
		int mid = (tl+tr)/2;
		if(ind <= mid){
			update(ind, k, v*2, tl, mid);
		} else {
			update(ind, k, v*2+1, mid+1, tr);
		}
		st[v] = merge(st[v*2], st[v*2+1]);
	}
	
}

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	long long c;
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &c);
		update(i, c, 1, 1, n);
	}
	
	int x, k;
	for(int i = 0; i < m; ++i){
		scanf("%d %d", &x, &k);
		update(x, k, 1, 1, n);
		printf("%lld\n", st[1].m);
	}
	
	return 0;
}

