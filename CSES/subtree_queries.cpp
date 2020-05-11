#include <bits/stdc++.h>

std::vector<int> adj[200001];

int right[200001];
int indDfs[200001];

int curDfs;

long long vals[200001];
long long arr[200001];
long long t[800004];


void dfs(int v, int p){
	
	curDfs++;
	indDfs[v] = curDfs;
	for(int nxt : adj[v]){
		if(nxt != p){
			dfs(nxt, v);
		}

		right[v] = curDfs;
	}
}

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = arr[tl];
		return;
	}
	
	int mid = (tl+tr)/2;
	build(v*2, tl, mid);
	build(v*2+1, mid+1, tr);
	t[v] = t[v*2]+t[v*2+1];
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
	t[v] = t[v*2] + t[v*2+1];
}

long long sum(int v, int tl, int tr, int l, int r){
	
	if(r < tl || l > tr){
		return 0;
	}
	
	if(l <= tl && tr <= r){
		return t[v];
	}
	
	int mid = (tl + tr)/2;
	return sum(v*2, tl, mid, l, r) + sum(v*2+1, mid+1, tr, l, r);
}

int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);
	
	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &vals[i]);
	}
	
	int a, b;
	for(int i = 0; i < n-1; ++i){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	curDfs = 0;
	dfs(1, 0);
	
	for(int i = 1; i <= n; ++i){
		arr[indDfs[i]] = vals[i];
	}
	
	build(1, 1, n);
	
	int x, c, d;
	while(q--){
		scanf("%d", &x);
		if(x == 1){
			scanf("%d %d", &c, &d);
			update(1, indDfs[c], d, 1, n);

		} else {
			scanf("%d", &c);
			//std::cout << indDfs[c] << right[c] << std::endl;
			std::cout << sum(1, 1, n, indDfs[c], right[c]) << std::endl;
		}	
	}
	
	return 0;
}

