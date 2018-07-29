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
ll p[mn],ql[mn],qr[mn],a[mn],L[mn],R[mn];
ll t[2*mn];
vector<ll> owns[mn],check[mn];
ll segn;
void modify(ll l, ll r, ll value) {
	++r;
	ll n=segn;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

ll query(ll p) {
	ll n=segn;
  ll res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=m;i++) {
		ll owner; scanf("%lld",&owner);
		owns[owner].PB(i);
	}
	for (ll i=1;i<=n;i++) scanf("%lld",p+i);
	ll k;scanf("%lld",&k);
	for (ll i=1;i<=k;i++) {
		scanf("%lld%lld%lld",ql+i,qr+i,a+i);
	}
	for (ll i=1;i<=n;i++) {
		L[i]=1; R[i]=k+1;
	}
	segn=m+1;
	bool changed=true;
	while(changed) {
		changed=false;
		memset(t,0,sizeof t);
		for (ll i=0;i<=k+1;i++) check[i].clear();
		for (ll i=1;i<=n;i++) {
			if (L[i]<R[i]) {
				ll mid=(L[i]+R[i])/2;
				check[mid].PB(i);
				changed=true;
				//printf("%lld:%lld %lld mid:%lld\n",i,L[i],R[i],mid);
			}
		}
		for (ll q=1;q<=k;q++) {
			ll l=ql[q],r=qr[q];
			if (l>r) {
				modify(1,r,a[q]);
				modify(l,m,a[q]);
			}
			else modify(l,r,a[q]);
			for (auto &state:check[q]) {
				ll sum=0;
				for (auto &point:owns[state]) {
					sum+=query(point);
					if (sum>=p[state]) break;
				}
				//printf("q:%lld state:%lld sum:%lld\n",q,state,sum);

				if (sum>=p[state]) {
					R[state]=q;
				}
				else {
					L[state]=q+1;
				}
			}
		}
	}
	for (ll i=1;i<=n;i++) {
		ll t=L[i];
		assert(L[i]==R[i]);
		if (t>k) {
			printf("NIE\n");
		}
		else printf("%lld\n",t);
	}
}

