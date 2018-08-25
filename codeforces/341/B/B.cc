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
const int mn=1e5+4;
int x[mn],p[mn],m[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) x[i]=rint();
  int l=0;
  for (int i=0;i<=n-1;i++) {
    int lo=1; int hi=l;
    while (lo<=hi) {
      int mid=(lo+hi+1)>>1;
      if (x[m[mid]]<x[i]) lo=mid+1;
      else hi=mid-1;
    }
    int newl=lo;
    p[i]=m[newl-1];
    m[newl]=i;
    if (newl>l) l=newl;
  }
  printf("%d\n",l);
}

