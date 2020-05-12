#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(int x){
	string str = to_string(x);
	int n = str.length();
	for(int i = 0; i < n/2; ++i){
		if(str[i] != str[n-i-1]) return false;
	}
	return true;
}

int main(){	

	int maxp = 0;
	for(int i = 999; i >= 100; --i){
		for(int j = 999; j >= 100; --j){
			if(is_palindrome(i*j)){
				maxp = max(maxp, i*j);
			}
		}
	}
	cout << maxp;

	return 0;
}