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
const ll mn=2e5+4;
ll a[mn];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; scanf("%lld%lld",&n,&k);
	for (ll i=0;i<n;i++) scanf("%lld",a+i);
	set<ll> s;
	for (ll i=0;i<n;i++) {
		if (a[i]<0) {
			s.insert(i);
		}
	}
	ll left=k-s.size();
	if (left<0) {
		printf("-1\n");
	}
	s.insert(-1);
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	ll past=-1;
	for (auto &w:s) {
		if (w!=-1) {
			ll num=w-past-1;
			pq.insert(MP(num,past));
		}
		past=w;
	}
}

