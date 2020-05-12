#include <bits/stdc++.h>
using namespace std;

vector<bool> SieveOfEratosthenes(int n){
	vector<bool> prime(n, 1);
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    return prime;
}

int main(){	

	long long n = 600851475143;
	vector<bool> prime = SieveOfEratosthenes(sqrt(n));
	for(int i = sqrt(n); i >= 1; --i){
		if(prime[i] && n%i == 0){
			cout << i;
			break;
		}
	}

	return 0;
}