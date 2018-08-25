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
int a[10000];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k=rint();
	int n=2*k-1;
	for (int i=0;i<n;i++) a[i]=rint();
	ll ans=0;
	if (k&1) {
		for (int i=0;i<n;i++) ans+=abs(a[i]);
	}
	else {
	sort(a,a+n);
	for (int i=0;i<n;i+=2) {
		if (i+1>=n) {
			ans+=a[i];
			break;
		}
		int x=a[i],y=a[i+1];
		int sum=x+y;
		ans+=max(-sum,sum);
	}}
	printf("%lld\n",ans);
}

