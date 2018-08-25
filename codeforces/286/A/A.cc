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
const int mn=1e6+4;
int p[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
	if (n%4==0||n%4==1) {
		for (int x=0;x<n/4;x++) {
			int a=2*x+1;
			int b=2*x+2;
			int c=n-2*x-1;
			int d=n-2*x;
			p[a]=b;
			p[b]=d;
			p[d]=c;
			p[c]=a;
		}
		if (n%4==1) {
			int mid=(n+1)/2;
			p[mid]=mid;
		}
		for (int x=1;x<=n;x++) printf("%d ",p[x]);
		printf("\n");
	}
	else {
		printf("-1\n");
	}
}

