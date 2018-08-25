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
const int mn=35000+2;
int f[2][mn],a[mn];
int vcnt[mn];
int cur=0,nxt=1;
int live;
void vinc(int x) {
  if (vcnt[x]==0) live++;
  vcnt[x]++;
}
void vdec(int x) {
  if (vcnt[x]==1) live--;
  vcnt[x]--;
}
int tmpdec(int x) {
  if (vcnt[x]==1) return live-1;
  return live;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),klim=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int k=0;k<klim;k++) {
    memset(f[nxt],0,sizeof f[nxt]);
    live=0;
    memset(vcnt,0,sizeof vcnt);
    int l=0;
    for (int r=0;r<n;r++) {
      vinc(a[r]);
      while (l<r&&f[cur][l]+live<=f[cur][l+1]+tmpdec(a[l])) {
        vdec(a[l]);
        l++;
      }
      printf("k:%d r:%d l:%d fcl:%d live:%d sum:%d\n",k,r,l,f[cur][l],live,f[cur][l]+live);
      f[nxt][r+1]=f[cur][l]+live;
    }
    swap(cur,nxt);
  }
  printf("%d\n",f[cur][n]);
}

