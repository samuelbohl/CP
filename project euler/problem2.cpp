#include <bits/stdc++.h>
using namespace std;

int main(){	

	//starting with 1 - 1 - 2 - ...
	int last1 = 1; int last2 = 1;
	int cur = last1+last2;
	
	int sum = 0;
	while(cur < 4000000){
		//check if even
		if(cur%2 == 0) sum+=cur;
		
		//next fibonacci number
		last2 = last1;
		last1 = cur;
		cur = last1+last2;
	}
	cout << sum;

	return 0;
}