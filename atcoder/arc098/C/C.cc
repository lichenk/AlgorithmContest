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
const int mn=3e5+4;
int pree[mn];
int prew[mn];
void solve(int n, string s){
	for (int i=n-1;i>=1;i--) {
		pree[i]=pree[i+1]+((s[i]=='E')?1:0);
	}
	for (int i=0;i<n;i++) {
		prew[i+1]=prew[i]+((s[i]=='W')?1:0);
	}
	int ans=INT_MAX;
	for (int i=0;i<n;i++) {
		int got=prew[i]+pree[i+1];
		//printf("got:%d\n",got);
		chkmin(ans,got);
	}
	printf("%d\n",ans);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	string S;
	cin>>N;
	cin >> S;
	solve(N, S);
	return 0;
}

