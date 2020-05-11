#include <bits/stdc++.h>
using namespace std; 

long long t[800000];

void build(int v, int tl, int tr, int a[]){
	if(tl == tr){
		t[v] = a[tl];
	} else {
		int mid = (tl+tr)/2;
		build(v*2, tl, mid, a);
		build(v*2+1, mid + 1, tr, a);
		
		t[v] = min(t[v*2], t[v*2+1]);
		
	}
	
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
	int a[n+1];
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	
	build(1, 1, n, a);
	
	int b, c;
	long long res = 0;
	for(int i = 0; i < q; ++i){
		scanf("%d %d", &b, &c);
		res = getMin(1, 1, n, b, c);
		cout << res << endl;
	}
	
	
	return 0;
}

