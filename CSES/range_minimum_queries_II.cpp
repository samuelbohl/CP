#include <bits/stdc++.h>
using namespace std; 

long long t[800000];

void build(int v, int tl, int tr, long long a[]){
	if(tl == tr){
		t[v] = a[tl];
	} else {
		int mid = (tl+tr)/2;
		build(v*2, tl, mid, a);
		build(v*2+1, mid + 1, tr, a);
		
		t[v] = min(t[v*2], t[v*2+1]);
		
	}
	
}

void update(int v, int ind, int k, int tl, int tr){
	if(ind < tl || ind > tr){
		return;
	}
	if(tl == tr){
		t[v] = k;
		return;
	}
	int mid = (tl+tr)/2;
	if(ind <= mid){
		update(v*2, ind, k, tl, mid);
	}
	if(ind >= mid+1){
		update(v*2+1, ind, k, mid+1, tr);
	}
	
	t[v] = min(t[v*2], t[v*2+1]);
}

long long getMin(int v, int tl, int tr, int l, int r){
	if(tr < l || tl > r){
		return LLONG_MAX;
	} 
	
	if(l <= tl && tr <= r) {
		return t[v];
	}
	
	int mid = (tl + tr)/2;
	return min(getMin(v*2, tl, mid, l, r), getMin(v*2+1, mid+1, tr, l, r));
	
}

int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);
	long long a[200001];
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	
	build(1, 1, n, a);
	
	int x, b, c;
	long long res = 0;
	for(int i = 0; i < q; ++i){
		scanf("%d", &x);
		if(x == 1){
			scanf("%d %d", &b, &c);
			update(1, b, c, 1, n);
		} else {
			scanf("%d %d", &b, &c);
			res = getMin(1, 1, n, b, c);
			printf("%lld\n", res);
		}
		
	}
	
	
	return 0;
}

