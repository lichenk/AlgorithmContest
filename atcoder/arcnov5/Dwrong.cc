#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll mn=3e5+4;
ll t[mn*2];
// T[i] += value
void fenwick_add(ll i, ll value, ll n) {
  for (; i < n; i |= i + 1)
    chkmax(t[i], value);
}

  // sum[0..i]
ll fenwick_max(ll i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    chkmax(res, t[i]);
  return res;
}
map<ll,pll> h;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll w,hh,n; scanf("%lld%lld%lld",&w,&hh,&n);
	for (ll i=0;i<n;i++) {
		ll x,y; scanf("%lld%lld",&x,&y);
		auto it=h.find(x);
		if (it==h.end()) {
			h[x]=MP(y,y);
		}
		else {
			chkmin(it->second.first,y);
			chkmax(it->second.second,y);
		}
	}
	ll fn=h.size();
	ll idx=fn-1;
	ll ans=0;
	memset(t,0,sizeof t);
	for (auto it=h.rbegin();it!=h.rend();++it) {
		ll x=it->first;
		ll l=it->second.first,u=it->second.second;
		ll dist=u-l;
		ll q=fenwick_max(fn-1)-x;
		chkmax(ans,q);
		fenwick_add(idx,dist+w-x,fn);
		--idx;
	}
	printf("%lld\n",ans*2);
}

