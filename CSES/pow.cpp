#include <bits/stdc++.h>

int pow(int base, int exp)
{
	int res = 1;
	for (; exp; exp >>= 1)
	{
		if (exp & 1) res *= base;
		base *= base;
	}
	return res;
}
 
int main() {
	// your code goes here
	std::cout << pow(2,10) << std::endl;
	return 0;
}
