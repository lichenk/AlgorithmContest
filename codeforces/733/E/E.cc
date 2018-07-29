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
const ll mn=1e6+4;
char s[mn];
ll downr[mn],upr[mn];
ll downl[mn],upl[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld\n",&n);
	for (ll i=0;i<n;i++) {
		scanf("%c",s+i);
	}
	{
		ll downs=0,ups=0;
		for (ll i=n-1;i>=0;i--) {
			downr[i]=downs;
			upr[i]=ups;
			if (s[i]=='D') downs++;
			if (s[i]=='U') ups++;
		}
	}
	{
		ll downs=0,ups=0;
		for (ll i=0;i<n;i++) {
			downl[i]=downs;
			upl[i]=ups;
			if (s[i]=='D') downs++;
			if (s[i]=='U') ups++;
		}
	}
	for (ll x=0;x<n;x++) {
		if (s[x]=='U') {
			
		}
	}
}

