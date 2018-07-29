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
typedef pair<ll,pair<ll,ll> > ppll;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,a,b,k; cin>>n>>a>>b>>k;
	string s; cin>>s;
	s='1'+s+'1';
	ll prev=-1;vector<pll> v;
	--a;
	vector<ll> out;
	for (ll i=0;i<s.length();i++) {
		if (s[i]=='1') {
			ll d=i-prev-1;
			{
				ll x=d;
				ll have=(x+2*b-2)/(2*b-1);
				ll skip=1;
				for (ll j=0;j<have;j++) {
					if (skip&&a>0) {
						skip=0;
						a--;
					}
					else {
						out.PB(prev+1+j*(2*b-1)+b-1);
						skip=1;
					}
				}
			}
			prev=i;
		}
	}
	ll ans=out.size();
	printf("%lld\n",ans);
	for (auto &w:out) printf("%lld ",w);
	printf("\n");
}
