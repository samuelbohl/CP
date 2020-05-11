#include <bits/stdc++.h>

const int MAX_N = 200001;
long long arr[2*MAX_N];
long long val[MAX_N];

long long t[8*MAX_N];

int pre[MAX_N];
int post[MAX_N];

std::vector<int> adj[MAX_N];

int dfsNum;

void dfs(int v, int p){

	pre[v] = ++dfsNum;
	arr[pre[v]] = val[v];
	for(int nxt : adj[v]){
		if(nxt != p){
			dfs(nxt, v);
		}
	}
	post[v] = ++dfsNum;
	arr[post[v]] = -1*val[v];
	
}

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = arr[tl];
		return;
	}
	
	int mid = (tl+tr) /2;
	build(v*2, tl, mid);
	build(v*2+1, mid+1, tr);
	t[v] = t[v*2] + t[v*2+1];
	
	
}

long long sum(int v, int tl, int tr, int l, int r){
	if(l <= tl && tr <= r){
		
		return t[v];
	}
	
	if(tr > l || tl > r){
		
		return 0;
	}
	
	int mid = (tl+tr)/2;
	long long res = sum(v*2, tl, mid, l, r) + sum(v*2+1, mid+1, tr, l, r);
	//std::cout << res << std::endl;
	return res;
}

void update(int v, int ind, int k, int tl, int tr){
	if(tl == tr){
		t[v] = k;
		return;
	}
	int mid = (tl+tr)/2;
	if(ind <= mid){
		update(v*2, ind, k, tl, mid);
	} else {
		update(v*2+1, ind, k, mid+1, tr);
	}
	t[v] = t[v*2]+t[v*2+1];
}

int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);
	
	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &val[i]);
	}
	
	int a, b;
	for(int i = 0; i < n-1; ++i){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, 0);
	
	build(1, 1, 2*n);
	
	int x, c, d;
	while(q-- > 0){
		
		scanf("%d", &x);
		
		if(x == 1){
			scanf("%d %d", &c, &d);
			update(1, pre[c], d, 1, 2*n);
			update(1, post[c], -1*d, 1, 2*n);
			

		} else {
			scanf("%d", &c);
			//std::cout << indDfs[c] << right[c] << std::endl;
			std::cout << sum(1, 1, 2*n, pre[c], post[c]) << std::endl;
		}	
	}
	
	return 0;
}

