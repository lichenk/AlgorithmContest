#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

void solve(vector<long long> a){
	sort(a.begin(),a.end());
	printf("%lld\n",a[2]-a[0]);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<long long> A(3-1+1);
	for(int i = 0 ; i <= 3-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(A);
	return 0;
}

