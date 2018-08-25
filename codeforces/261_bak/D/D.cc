//#ifdef ZZLICHEN_USE_CACHED_HEADERS
#include "bits/stdc++.h"
//#else
//#include <bits/stdc++.h>
//#endif
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
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

const int mn=2e7+2;
int f[mn];

int longest_strictly_increasing_subsequence(vector<int> &p, int maxval, int repeats) {
  memset(f,0,sizeof(int)*(maxval+1));
  for (int r=0;r<repeats;r++) {
    for (auto &x:p) {
      int best=f[x-1]+1;
      for (int y=x;y<=maxval;y++) {
        if (f[y]<best) f[y]=best;
        else break;
      }
    }
  }
  return f[maxval];
}

int compress(vector<int> &vinp) {
  vector<int> bintable=vinp;
  makeunique(bintable);
  for (auto &w:vinp) {
    w=bins(bintable,w)+1;
  }
  return (int)bintable.size();
}


int n,t;

vector<int> b;
void solve() {
  for (int i=0;i<n;i++) b[i]=rint();
  int maxval=compress(b);
  int ans=longest_strictly_increasing_subsequence(b, maxval, min(t,maxval));
  printf("%d\n",ans);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int numtests,maxb;
  numtests=rint(),n=rint(),maxb=rint(),t=rint();
  b.resize(n);
  for (int test=0;test<numtests;test++) solve();
}





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