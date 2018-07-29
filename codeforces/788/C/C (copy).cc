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
ll n;
const int mn=1e3+2;
bool a[mn];
ll sign(ll x) {
	if (x>=0) return 1;
	else return -1;
}
vll solve(vll prefix) {
	while(prefix.size()>0 prefix.back()==0) prefix.pop_back();
	ll psz=prefix.size();
	if (psz==0) return 0;
	vll newprefix; newprefix.resize(psz-1);
	for (ll i=0;i<psz-1;i++) {
		newprefix[i]=(abs(prefix[i])%abs(prefix[psz-1]))*sign(prefix[i]);
	}
	vll prev=solve(newprefix);
	vll vans;
	ll BASE=mn+1;
	vans.resize(2*BASE+2);
	for (ll x=-mn;x<=mn;x++) {
		
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k;
	scanf("%lld%d",&n,&k);
	for (int i=0;i<k;i++) {
		int x; scanf("%d",&x);
		a[x]=true;
	}
}

