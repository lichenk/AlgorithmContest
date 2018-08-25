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
const int mn=100+2;
int f[2][mn];
int a[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),klim=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  int cur=0,nxt=1;
  for (int k=0;k<klim;k++) {
    memset(f[nxt],0,sizeof f[nxt]);
    for (int l=0;l<n;l++) {
      int now=f[cur][l];
      set<int> s;
      for (int r=l;r<n;r++) {
        s.insert(a[r]);
        chkmax(f[nxt][r+1],now+(int)s.size());
      }
    }
    swap(cur,nxt);
  }
  printf("%d\n",f[cur][n]);
}

