#include <bits/stdc++.h>

const int MAX_N = 1e6 +1;
char str[MAX_N];
int cnt[27];
std::vector<char> vec;

void swap(int x, int y){
	char temp = str[x];
	str[x] = str[y];
	str[y] = temp;
}

int main(){
	
	scanf("%s", str);
	int n = strlen(str);
	

	for(int i = 0; i < n; ++i){
		++cnt[str[i] - 'A'];
	}
	
	int ne = 0;
	int ind = -1;
	for(int i = 0; i < 27; ++i){
		if(cnt[i] % 2){
			++ne;
			ind = i;
			if(ne >= 2){
				printf("NO SOLUTION");
				return 0;
			}
		}
	}
	
	for(int i = 0; i < 27; ++i){
		for(int j = 0; j < cnt[i] / 2; ++j){
			vec.push_back((char) (i+'A'));
		}
	}
	for(int i = 0; i < vec.size(); ++i){
		printf("%c", vec[i]);
	}
	if(ind != -1){
		printf("%c", (char) ind + 'A');	
	}
	std::reverse(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); ++i){
		printf("%c", vec[i]);
	}
	

	return 0;
}

