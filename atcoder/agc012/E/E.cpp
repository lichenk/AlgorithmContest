#include <bits/stdc++.h>
using namespace std;

void solve(long long N, long long V, vector<long long> x){
	
}

int main(){	
	long long V;
	long long N;
	scanf("%lld",&N);
	vector<long long> x(N-1+1);
	scanf("%lld",&V);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&x[i]);
	}
	solve(N, V, x);
	return 0;
}

