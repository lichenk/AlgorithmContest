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
const ll maxn=1002;
bool black[maxn][maxn];
ll a[maxn][maxn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll h,w,n;
	scanf("%lld%lld%lld",&h,&w,&n);
	for (ll i=0;i<n;i++) {
		ll x,y; scanf("%lld%lld",&x,&y);
		--x;--y;
		black[x][y]=1;
	}
	a[0][0]=1;
	for (ll d=0;d<=h+w-2;d++) {
		for (ll x=0;x<=d;x++) {
			ll y=d-x;
			if (y<0) continue;
			a[x][y]%=MOD;
			if (!black[x+1][y]) a[x+1][y]+=a[x][y];
			if (!black[x][y+1]) a[x][y+1]+=a[x][y];
		}
	}
	printf("%lld\n",a[h-1][w-1]%MOD);
}

