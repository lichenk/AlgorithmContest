#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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

const int MAXN = 2e5+2;  // limit for array size
int segn;  // array size
int t[2 * MAXN];

void modify(int l, int r, int value) {
	int n=segn;
	r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] = value;
    if (r&1) t[--r] = value;
  }
}

int query(int p) {
	int n=segn;
  int res = -1;
  for (p += n; p > 0; p >>= 1) {
  	if (t[p]!=-1) res = t[p];
  }
  return res;
}


int rint()
{
  int x; scanf("%d",&x); return x;
}


int main() 
{
	ll n=rint(),q=rint();
	memset(t,-1,sizeof t);
	segn=n;
	for (ll x=0;x<n;x++) {
		t[segn+x]=x;
	}
	for (ll i=0;i<q;i++) {
		ll type=rint(),x=rint(),y=rint();
		--x; --y;
		if (type==1) {
			ll tx=query(x);
			ll ty=query(y);
			funion(tx,ty);
		}
	}
}

