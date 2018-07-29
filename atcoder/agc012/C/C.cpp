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
void solve(long long n){
	vll v;
	n++;
	while(n>1) {
		if (n%2==1) {v.PB(1); n--;}
		else {v.PB(2); n/=2;}
	}
	reverse(v.begin(),v.end());
	ll id=1;
	vll a,b;
	for (auto &w:v) {
		//printf("id:%d w:%d\n",id,w);
		if (w==1) {
			a.PB(id);
			b.insert(b.begin(),id);
		}
		else {
			a.PB(id); b.PB(id);
		}
		id++;
	}
	ll sz=a.size()+b.size();
	printf("%lld\n",sz);
	for (auto &w:a) printf("%lld ",w);
	for (auto &w:b) printf("%lld ",w);
	printf("\n");
}

int main(){	
	long long N;
	scanf("%lld",&N);
	solve(N);
	return 0;
}

