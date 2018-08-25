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
const int mn=1e5+4;
int a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
	for (int i=0;i<n;i++) a[i]=rint();
	sort(a,a+n);
	ll imin=0,imax=2e9;
	while(imin<imax) {
		ll imid=(imin+imax)>>1;
		ll sup=0;
		bool ok=1;
		for (int i=0;i<n;i++) {
			ll add=imid-a[i];
			if (add<0) {ok=0;break;}
			sup+=add;
		}
		if (sup<imid) ok=0;
		if (!ok) imin=imid+1;
		else imax=imid;
	}
	printf("%lld\n",imin);
}

