#include <bits/stdc++.h>
using namespace std;

void solve(long long N, vector<long long> a){
	
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> a((2*N-1)-1+1);
	for(int i = 0 ; i <= (2*N-1)-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(N, a);
	return 0;
}

