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
const int mn=2e3+4;
int a[mn],b[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),k=rint(),p=rint();
	for (int i=0;i<n;i++) a[i]=rint();
	for (int i=0;i<k;i++) b[i]=rint();
	sort(a,a+n); sort(b,b+k);
	ll final=1LL<<62;
	for (int init=0;init<=(k-n);init++) {
		ll ans=0;
		for (int i=0;i<n;i++) {
			ll x=a[i],y=b[i+init];
			ll got=abs(x-y)+abs(y-p);
			chkmax(ans,got);
		}
		chkmin(final,ans);
	}
	printf("%lld\n",final);
}

