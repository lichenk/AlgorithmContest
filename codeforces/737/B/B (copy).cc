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
	for (ll i=0;i<s.length();i++) {
		if (s[i]=='1') {
			ll d=i-prev-1;
			if (d>=b) {
				ll x=d;
				v.PB(MP(x,prev+1));
			}
			prev=i;
		}
	}
	priority_queue<ppll,vector<ppll>,greater<ppll> > pq;
	for (auto &got:v) {
		ll x=got.first,idx=got.second;
		ll r=(x+2*b-2)%(2*b-1);
		pq.push(MP(r,MP(x,idx)));
	}
	--a;
	while(a>0&&!pq.empty()) {
		auto got=pq.top(); pq.pop();
		ll x=got.second.first,idx=got.second.second;
		--a;
		x-=b;
		if (x>=b) {
			ll r=(x+2*b-2)%(2*b-1);
			pq.push(MP(r,MP(x,idx)));
		}
	}
	ll ans=0;
	vector<ll> out;
	while(!pq.empty()) {
		auto got=pq.top(); pq.pop();
		ll x=got.second.first,idx=got.second.second;
		ll add=(x+2*b-2)/(2*b-1);
		for (ll j=0;j<add;j++) {
			out.PB(idx+j*(2*b-1)+b-1);
		}
		ans+=add;
	}
	printf("%lld\n",ans);
	for (auto &w:out) printf("%lld ",w);
	printf("\n");
}

