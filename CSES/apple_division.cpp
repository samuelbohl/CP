#include <bits/stdc++.h>

const int MAX_N = 21;

long long m = LONG_MAX;
long long sum;
int arr[MAX_N];
int n;



void generate(int i, std::vector<int> left, std::vector<int> right){
	
	if(i == n){
		if(left.size() + right.size() < n){
			return;
		}
		sum = 0;
		for(int i = 0; i < left.size(); ++i){
			sum -= left[i];
		}
		for(int i = 0; i < right.size(); ++i){
			sum += right[i];
		}
		m = std::min(m, std::abs(sum));
		//std::cout << m << "\n";
		return;
	}
	left.push_back(arr[i]);
	generate(i+1, left, right);
	
	left.pop_back();
	
	right.push_back(arr[i]);
	generate(i+1, left, right);
	
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		scanf("%lld ", &arr[i]);
	}
	std::vector<int> l;
	std::vector<int> r;
	generate(0, l, r);
	
	
	printf("%lld", m);
	

	return 0;
}

