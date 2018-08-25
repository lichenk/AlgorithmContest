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
int a[mn];
pii b[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	int l=-1,r=1;
	a[n-1]=0;
	for (int x=n-2;x>=0;x--) {
		if (s[x]=='l') {
			a[x]=++r;
		}
		else {
			a[x]=--l;
		}
	}
	for (int x=0;x<n;x++) b[x]=MP(a[x],x);
	sort(b,b+n);
	for (int x=0;x<n;x++) printf("%d\n",b[x].snd+1);
}

