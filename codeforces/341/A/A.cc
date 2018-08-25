#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1e5+2;
int a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
	for (int i=0;i<n;i++) a[i]=rint();	
	sort(a,a+n);
	ll presum=0;
	ll all=0;
	for (int i=0;i<n;i++) {
		ll x=a[i];
		ll contrib=x*i-presum;
		//printf("x:%lld i:%lld presum:%lld contrib:%lld\n",x,i,presum,contrib);
		all+=contrib;
		presum+=x;
	}
	ll numer=2*all+presum;
	ll denom=n;
	ll g=__gcd(numer,denom);
	numer/=g; denom/=g;
	printf("%lld %lld\n",numer,denom);
}

